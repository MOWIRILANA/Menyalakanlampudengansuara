#define RELAY_PIN 23
#define SENSOR_PIN 22 // ESP32 pin GPIO18 connected to the OUT pin of the sound sensor

int lastState = HIGH;  // the previous state from the input pin
int currentState;      // the current reading from the input pin

void setup() {
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  currentState = digitalRead(SENSOR_PIN);

  if (lastState == HIGH && currentState == LOW){
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("The sound has been detected");
    delay(10000);
    }
  else if (lastState == LOW && currentState == HIGH){
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("The sound has disappeared");
    }

  lastState = currentState;
}

