import numpy as np
import librosa
import tensorflow.lite as tflite
import matplotlib.pyplot as plt

# --- Load sound.csv as a waveform
csv_file = "sound.csv"
raw_audio = np.loadtxt(csv_file, delimiter=",", skiprows=1, usecols=1)  # shape: (samples,)

# --- Preprocess audio
sample_rate = 16000  # match Edge Impulse setting
if len(raw_audio.shape) > 1:
    raw_audio = raw_audio[:, 0]  # flatten if stereo

# Resample if needed
if sample_rate != 16000:
    raw_audio = librosa.resample(raw_audio, orig_sr=sample_rate, target_sr=16000)

# --- Generate MFCCs (13 coeffs, match Edge Impulse)
mfcc = librosa.feature.mfcc(y=raw_audio, sr=16000, n_mfcc=13, n_fft=512, hop_length=160)

# Transpose to (frames, 13), then flatten
input_features = mfcc.T.flatten().astype(np.int8)

# Resize or pad to expected input length (e.g., 1950)
expected_input_len = 15873  # ← match your model input shape
if input_features.shape[0] < expected_input_len:
    # Pad with zeros
    input_features = np.pad(input_features, (0, expected_input_len - input_features.shape[0]), 'constant')
else:
    input_features = input_features[:expected_input_len]  # truncate if too long

# --- Load TFLite model
interpreter = tflite.Interpreter(model_path="tflite-model/tflite_learn_4.tflite")
interpreter.allocate_tensors()
input_details = interpreter.get_input_details()
output_details = interpreter.get_output_details()

print("Expected shape:", input_details[0]['shape'])

# --- Run Inference
interpreter.set_tensor(input_details[0]['index'], np.array([input_features]))
interpreter.invoke()
output_data = interpreter.get_tensor(output_details[0]['index'])

# --- Print Results
print("Output:", output_data)
predicted_label = np.argmax(output_data)
print("Predicted class index:", predicted_label)
