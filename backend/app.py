from flask import Flask, request, jsonify
from flask_cors import CORS
import subprocess

app = Flask(__name__)
CORS(app)  

@app.route("/")
def home():
    return "Backend berjalan"

@app.route("/check", methods=["POST"])
def check():
    data = request.get_json()
    n = str(data["n"])
    mode = data["mode"]

    proses = subprocess.run(
        ["../cpp/prima", n, mode],
        capture_output=True,
        text=True
    )

    hasil, waktu = proses.stdout.strip().split()

    return jsonify({
        "hasil": hasil,
        "waktu": waktu
    })

if __name__ == "__main__":
    app.run(debug=True)
