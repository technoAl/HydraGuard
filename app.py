from flask import Flask, jsonify, redirect, render_template, request
from flask_cors import CORS
import json

import numpy as np

def loadCsvSkipCommentAndRows(filename, skipRows):
    with open(filename) as f:
        lines = (line for line in f if not line.startswith('#'))
        return np.loadtxt(lines, delimiter=',', skiprows=skipRows)

app = Flask(__name__)
CORS(app)

@app.route('/', methods =["GET", "POST"])
def process():
    if request.method == "POST":
        with open('sensor.csv', 'a') as csv_file:
            json = request.get_json()
            Sweat = json['sweat']
            Temperature = json['temperature']
            Movement = json['movement']
            Index = 0
            row = ", ".join([str(Sweat), str(Temperature), str(Movement)]) + '\n'
            csv_file.write(row)
        return "Success"
    else:
        g=loadCsvSkipCommentAndRows("sensor.csv", 0)[-10:].swapaxes(0, 1).tolist()
        return jsonify(sweat=g[0], temperature=g[1], movement=g[2], hydration=g[3])

@app.route('/hour', methods =["GET"])
def hi():
    csv = loadCsvSkipCommentAndRows("sensor.csv", 0)
    g=[[np.average(csv[-(i+1)*60:-i*60,j]) for i in range(60)] for j in range(4)]
    g[0][0] = np.average(csv[-60:,0])
    g[1][0] = np.average(csv[-60:,1])
    g[2] = [np.sum(csv[-(i+1)*60:-i*60,2]) for i in range(60)]
    g[2][0] = np.sum(csv[-60:,2])
    g[3][0] = np.average(csv[-60:,3])
    return jsonify(sweat=g[0], temperature=g[1], movement=g[2], hydration=g[3])

@app.route('/onehour', methods =["GET"])
def hi2():
    csv = loadCsvSkipCommentAndRows("sensor.csv", 0)
    g = [0, 0, 0, 0]
    g[0] = np.average(csv[-60:,0])
    g[1] = np.average(csv[-60:,1])
    g[2] = np.sum(csv[-60:,2])
    g[3] = np.average(csv[-60:,3])
    return jsonify(sweat=g[0], temperature=g[1], movement=g[2], hydration=g[3])

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=20003)