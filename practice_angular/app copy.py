from flask import Flask, request, jsonify
from flask_cors import CORS
from Jarvis import listen, process_command, speak

app = Flask(__name__)
CORS(app)  # Allow Angular to connect

@app.route('/listen', methods=['GET'])
def listen_command():
    """Listen for a command and return the text."""
    command = listen()
    return jsonify({"command": command})

@app.route('/process', methods=['POST'])
def process():
    """Process the command received from Angular."""
    data = request.get_json()
    command = data.get("command", "")

    if not command:
        return jsonify({"response": "No command received."})

    response = process_command(command)
    speak(response)  # Ensure Jarvis speaks the response
    return jsonify({"response": response})

@app.route('/test-voice', methods=['GET'])
def test_voice():
    """Test if the voice response works."""
    speak("This is a test voice response.")
    return jsonify({"message": "Voice test triggered."})

if __name__ == "__main__":
    app.run(debug=True, 
