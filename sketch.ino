// SAGE Project - Phase 1 Sensor & Agent Logic
// Agents: Navigator (Distance) & Sentinel/EMBER (Human Presence)

// Pin Definitions based on diagram.json
const int frontTrig = 12;
const int frontEcho = 13;
const int rearTrig = 10;
const int rearEcho = 11;
const int pirPin = 2;

void setup() {
  // Serial communication with ESP32 at 9600 baud
  Serial.begin(9600); 
  
  pinMode(frontTrig, OUTPUT);
  pinMode(frontEcho, INPUT);
  pinMode(rearTrig, OUTPUT);
  pinMode(rearEcho, INPUT);
  pinMode(pirPin, INPUT);
  
  Serial.println("--- SAGE Hardware Initialized ---");
}

// Function to calculate distance in centimeters
long getDistance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  long duration = pulseIn(echo, HIGH);
  return duration * 0.034 / 2; // Speed of sound conversion
}

void loop() {
  // 1. Navigator Agent: Get obstacle data
  long frontDist = getDistance(frontTrig, frontEcho);
  long rearDist = getDistance(rearTrig, rearEcho);
  
  // 2. Sentinel/EMBER Agent: Check for human presence
  int humanDetected = digitalRead(pirPin);

  // 3. IoT Data Bridge: Send formatted string to ESP32
  // This format allows the ESP32 to parse data for AWS IoT Core
  Serial.print("FRONT:"); Serial.print(frontDist);
  Serial.print("|REAR:"); Serial.print(rearDist);
  Serial.print("|HUMAN:"); Serial.println(humanDetected);

  // Delay to prevent serial flooding (500ms for real-time feel)
  delay(500); 
}
