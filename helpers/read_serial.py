import serial
import csv
import time

ser = serial.Serial('COM5', 9600)  # Replace with your port
output_file = open('output.csv', 'w', newline='')
writer = csv.writer(output_file)

# Write CSV header
writer.writerow(["timestamp", "pitch"])

start_time = time.time()
duration = 10  # seconds

try:
    while time.time() - start_time < duration:
        line = ser.readline().decode('utf-8').strip()
        timestamp = time.time() - start_time  # relative time in seconds
        print(f"{timestamp:.4f}, {line}")
        writer.writerow([timestamp, line])
except Exception as e:
    print("Error:", e)
finally:
    output_file.close()
    ser.close()
    print("Data collection complete.")
