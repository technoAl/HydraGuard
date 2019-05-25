from flask import Flask
import csv
import requests
import json

app = Flask(__name__)


@app.route('/', methods =["GET", "POST"])

def hello_world():
    return 'Hello World!'
with open('sensor.csv', 'w') as csv_file:
    writer = csv.writer(csv_file)
    # Write a header row with the name of each column.
    writer.writerow(['Sweat', 'Humidity', 'Temperature'])
     while True:
     	sweat = request.get_json
     	humidity = request.get_json
     	temperature = request.get_json
     	writer.writerow([sweat, humidity, temperature])
     	time.sleep(1);
