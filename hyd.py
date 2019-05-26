from flask import Flask, redirect, render_template, request
import csv
import json

app = Flask(__name__)


@app.route('/', methods =["GET", "POST"])
	if request.method == "POST":
def collect():
with open('sensor.csv', 'w') as csv_file:
    writer = csv.writer('sensor.csv')
    # Write a header row with the name of each column.
    writer.writerow(['Sweat', 'Humidity', 'Temperature'])
     while True:
     	sweat = request.get_json('sweat')
     	humidity = request.get_json('humidity')
     	temperature = request.get_json('temperature')
     	writer.writerow([sweat, humidity, temperature])
     	time.sleep(1);
	else:
		return render_template(“index.html”)
