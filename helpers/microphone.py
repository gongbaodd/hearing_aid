# Install first: pip install sounddevice numpy matplotlib
import sounddevice as sd
import numpy as np

duration = 2  # seconds
sample_rate = 16000  # Hz

print("Recording...")
samples = sd.rec(int(duration * sample_rate), samplerate=sample_rate, channels=1)
sd.wait()
print("Recording finished.")

# Save to CSV
np.savetxt("audio_data.csv", samples, delimiter=",")
