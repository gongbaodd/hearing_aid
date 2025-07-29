# Install first: pip install sounddevice numpy matplotlib
import sounddevice as sd
import numpy as np
import csv

duration = 2  # seconds
sample_rate = 16000  # Hz

print("Recording...")
samples = sd.rec(int(duration * sample_rate), samplerate=sample_rate, channels=1)
sd.wait()
print("Recording finished.")

# Flatten the samples from 2D to 1D
samples = samples.flatten()

# Generate timestamps
timestamps = np.linspace(0, duration, num=len(samples), endpoint=False)

# Save to CSV with headers: timestamp, pitch
with open("audio_data.csv", "w", newline="") as csvfile:
    writer = csv.writer(csvfile)
    writer.writerow(["timestamp", "pitch"])
    for t, p in zip(timestamps, samples):
        writer.writerow([f"{t:.6f}", f"{p:.6f}"])
