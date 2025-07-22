import pandas as pd
import numpy as np
import pickle
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.preprocessing import StandardScaler

# Load dataset
df = pd.read_csv("pune.csv")

# Define required features
required_features = ["maxtempC", "mintempC", "humidity", "pressure",
                     "windspeedKmph", "cloudcover", "sunHour", "DewPointC"]

# Check if `precipMM` exists
if "precipMM" not in df.columns:
    print("Available columns:", df.columns)
    raise ValueError("Target column 'precipMM' is missing in dataset!")

# Create a binary target column
df["Rain"] = df["precipMM"].apply(lambda x: 1 if x > 0 else 0)

# Select required features and target
df = df[required_features + ["Rain"]]

# Handle missing values
df.fillna(df.mean(), inplace=True)

# Split data
X = df[required_features]
y = df["Rain"]

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Scale features
scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

# Train model
model = RandomForestClassifier(n_estimators=100, random_state=42)
model.fit(X_train_scaled, y_train)

# Save model and scaler
with open("model.pkl", "wb") as f:
    pickle.dump(model, f)

with open("scaler.pkl", "wb") as f:
    pickle.dump(scaler, f)

print("Model training completed and saved!")
