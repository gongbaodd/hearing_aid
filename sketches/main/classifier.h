#include <esp32_inferencing.h>

#define AUDIO_PIN 7
#define SAMPLE_RATE 16000
#define SAMPLE_INTERVAL_US (1000000 / SAMPLE_RATE)
#define UNCERTAINTY_THRESHOLD 0.9

static unsigned int const FEATURES_COUNT = 3846;
static float features[FEATURES_COUNT];

int raw_feature_get_data(size_t offset, size_t length, float *out_ptr) {
    memcpy(out_ptr, features + offset, length * sizeof(float));
    return 0;
}

class Classifier {
    private:
        unsigned int index = 0;
        void read_features() {
            static unsigned long lastMicros = 0;
        

            while (index < FEATURES_COUNT)
            {
                unsigned long now = micros();
                if (now - lastMicros >= SAMPLE_INTERVAL_US) {
                    lastMicros = now;
                    int audioValue = analogRead(AUDIO_PIN);
                    features[index] = audioValue;
                    index++;
                }
            }
            index = 0;
        }
        void infer_audio() {
            if (sizeof(features) / sizeof(float) != EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE) {
                ei_printf("The size of your 'features' array is not correct. Expected %lu items, but had %lu\n",
                    EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE, sizeof(features) / sizeof(float));
                delay(1000);
                return;
            }
        
            ei_impulse_result_t result = { 0 };
        
            // the features are stored into flash, and we don't want to load everything into RAM
            signal_t features_signal;
            features_signal.total_length = sizeof(features) / sizeof(features[0]);
            features_signal.get_data = &raw_feature_get_data;
        
            // invoke the impulse
            EI_IMPULSE_ERROR res = run_classifier(&features_signal, &result, false /* debug */);
            if (res != EI_IMPULSE_OK) {
                ei_printf("ERR: Failed to run classifier (%d)\n", res);
                return;
            }
        
            // print inference return code
            // ei_printf("run_classifier returned: %d\r\n", res);
            // print_inference_result(result);
            set_result(result);
        }
        void print_inference_result(ei_impulse_result_t result) {

            // Print how long it took to perform inference
            ei_printf("Timing: DSP %d ms, inference %d ms, anomaly %d ms\r\n",
                    result.timing.dsp,
                    result.timing.classification,
                    result.timing.anomaly);
        
            // Print the prediction results (object detection)
            ei_printf("Predictions:\r\n");
            for (uint16_t i = 0; i < EI_CLASSIFIER_LABEL_COUNT; i++) {
                ei_printf("  %s: ", ei_classifier_inferencing_categories[i]);
                ei_printf("%.5f\r\n", result.classification[i].value);
            }
        }
        enum Result {
            BABY_CRYING,
            SIREN,
            PHONE,
            UNKNOWN
        };
        Result result = UNKNOWN;
        void set_result(ei_impulse_result_t result) {
            float maxValue = 0;
            String maxLabel = "";
            for (uint16_t i = 0; i < EI_CLASSIFIER_LABEL_COUNT; i++) {
                if (result.classification[i].value > maxValue) {
                    maxValue = result.classification[i].value;
                    maxLabel = ei_classifier_inferencing_categories[i];
                }
            }

            if (maxValue > UNCERTAINTY_THRESHOLD) {
                if (maxLabel == "cry") {
                    this->result = BABY_CRYING;
                } else if (maxLabel == "siren") {
                    this->result = SIREN;
                } else if (maxLabel == "phone") {
                    this->result = PHONE;
                }
                Serial.println("[classifier] Result: " + maxLabel + " " + String(maxValue));
            } else {
                this->result = UNKNOWN;
            }
        }
    public:
        void loop() {
            read_features();
            infer_audio();
        }

        bool isBabyCrying() {
            return this->result == BABY_CRYING;
        }
        bool isSiren() {
            return this->result == SIREN;
        }
        bool isPhone() {
            return this->result == PHONE;
        }
        bool isUnknown() {
            return this->result == UNKNOWN;
        }
};