#define VIBRATE_PIN 20
#define VIBRATING_TIME 1000
#define IGNORE_TIME 10000
#define BUTTON_PIN 4

class Vibrator {
    private:
        enum State {
            IDLE,
            VIBRATE,
            IGNORE
        };
        State state;
        unsigned long vibrateStartTime;
        unsigned long ignoreStartTime;
    public:
        Vibrator() {
            pinMode(VIBRATE_PIN, OUTPUT);
            pinMode(BUTTON_PIN, INPUT);

            state = IDLE;
        }
        void loop() {
            switch (state) {
                case IDLE:
                    digitalWrite(VIBRATE_PIN, LOW);
                    break;
                case VIBRATE:
                    digitalWrite(VIBRATE_PIN, HIGH);
                    if (millis() - this->vibrateStartTime > VIBRATING_TIME) {
                        this->transitionToIdle();
                    }
                    break;
                case IGNORE:
                    digitalWrite(VIBRATE_PIN, LOW);
                    if (millis() - this->ignoreStartTime > IGNORE_TIME) {
                        this->transitionToIdle();
                    }
                    break;
            }

            
            if (digitalRead(BUTTON_PIN) == HIGH) {
                this->transitionToIgnore();
            }
        }
        void transitionToVibrate() {
            if (this->state == IDLE) {
                this->vibrateStartTime = millis();
                this->state = VIBRATE;
                Serial.println("[vibrator STATE]: VIBRATE");
                this->loop();
            }
        }

        void transitionToIgnore() {
            this->ignoreStartTime = millis();
            this->state = IGNORE;
            Serial.println("[vibrator STATE]: IGNORE");
            this->loop();
        }

        void transitionToIdle() {
            if (this->state != IDLE) {
                this->state = IDLE;
                Serial.println("[vibrator STATE]: IDLE");
                this->loop();
            }
        }
};