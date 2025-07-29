import numpy as np
import matplotlib.pyplot as plt

# Load data from CSV
samples = np.loadtxt("clap.csv", delimiter=",")

# Generate time axis (in seconds)
sample_rate = 16000  # Hz
duration = len(samples) / sample_rate
time_axis = np.linspace(0, duration, len(samples))

# Plot
plt.figure(figsize=(12, 4))
plt.plot(time_axis, samples, linewidth=0.5)
plt.title("Audio Waveform")
plt.xlabel("Time (s)")
plt.ylabel("Amplitude")
plt.grid(True)
plt.tight_layout()
plt.show()