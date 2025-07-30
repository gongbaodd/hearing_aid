import numpy as np
import matplotlib.pyplot as plt

# Load data from CSV (skip header row)
data = np.genfromtxt("output.csv", delimiter=",", skip_header=1)

# Separate columns
timestamps = data[:, 0]
pitches = data[:, 1]

# Plot
plt.figure(figsize=(12, 4))
plt.plot(timestamps, pitches, linewidth=0.5)
plt.title("Audio Waveform")
plt.xlabel("Time (s)")
plt.ylabel("Pitch (Amplitude)")
plt.grid(True)
plt.tight_layout()
plt.show()
