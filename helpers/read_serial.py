import serial
import csv

# === Config ===
sample_rate = 1000  # Hz, must match Arduino
duration_seconds = 20
total_samples = duration_seconds * sample_rate

# === Setup serial and file ===
ser = serial.Serial('COM6', 115200, timeout=1)  # timeout prevents hanging
output_file = open('output.csv', 'w', newline='')
writer = csv.writer(output_file)
writer.writerow(["timestamp", "pitch"])

# === Collect ===
sample_index = 0

try:
    while sample_index < total_samples:
        line = ser.readline().decode('utf-8').strip()

        # Check if the line is a valid number
        try:
            value = int(line)
            timestamp = sample_index / sample_rate
            writer.writerow([f"{timestamp:.6f}", value])
            print(f"{timestamp:.6f}, {value}")
            sample_index += 1
        except ValueError:
            # Skip invalid/non-integer lines silently
            continue
except Exception as e:
    print("Error:", e)
finally:
    output_file.close()
    ser.close()
    print(f"✅ Collected {sample_index} samples in {duration_seconds}s. Done.")
