from flask import Flask, request, jsonify
import pandas as pd
import pickle
import numpy as np
from flask_cors import CORS

# Initialize Flask app
app = Flask(__name__)
CORS(app)

# Load trained model and scaler
with open("model.pkl", "rb") as f:
    model = pickle.load(f)

with open("scaler.pkl", "rb") as f:
    scaler = pickle.load(f)

# Define expected feature columns
feature_columns = ["maxtempC", "mintempC", "humidity", "pressure",
                   "windspeedKmph", "cloudcover", "sunHour", "DewPointC"]

@app.route("/predict", methods=["POST"])
def predict():
    try:
        # Get input JSON
        data = request.json
        print("Received data:", data)

        # Convert input to DataFrame
        input_df = pd.DataFrame([data])

        # Ensure all required features exist
        missing_cols = set(feature_columns) - set(input_df.columns)
        for col in missing_cols:
            input_df[col] = 0  # Fill missing columns with 0

        input_df = input_df[feature_columns]  # Reorder columns

        # Scale input
        input_scaled = scaler.transform(input_df)

        # Make prediction
        prediction = model.predict(input_scaled)[0]
        prediction_text = "Rainy" if prediction == 1 else "Sunny"

        print("Prediction:", prediction_text)
        return jsonify({"prediction": prediction_text})

    except Exception as e:
        return jsonify({"error": str(e)})

# Run Flask app
if __name__ == "__main__":
    app.run(debug=True)
