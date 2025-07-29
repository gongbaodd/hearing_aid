import serial
import csv
import time

ser = serial.Serial('COM3', 9600)  # Replace with your port
output_file = open('output.csv', 'w', newline='')
writer = csv.writer(output_file)

start_time = time.time()
duration = 2  # seconds

try:
    while time.time() - start_time < duration:
        line = ser.readline().decode('utf-8').strip()
        print(line)
        writer.writerow([line])  # or use line.split(',') if multiple values
except Exception as e:
    print("Error:", e)
finally:
    output_file.close()
    ser.close()
    print("Data collection complete.")