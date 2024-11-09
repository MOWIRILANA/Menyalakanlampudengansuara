#define RELAY_PIN 14    // Pin untuk relay atau lampu
#define SENSOR_PIN 22  // Pin sensor suara

int lastState = HIGH;   // Menyimpan kondisi terakhir dari sensor suara
int currentState;       // Menyimpan kondisi saat ini dari sensor suara
bool lampStatus = LOW;  // Status lampu, awalnya mati

void setup() {
  Serial.begin(9600);       
  pinMode(SENSOR_PIN, INPUT); 
  pinMode(RELAY_PIN, OUTPUT); 
  digitalWrite(RELAY_PIN, LOW); 
}

void loop() {
  currentState = digitalRead(SENSOR_PIN);

  // Jika suara terdeteksi (perubahan dari HIGH ke LOW)
  if (lastState == HIGH && currentState == LOW) {
    // Toggle status lampu (ON/OFF)
    lampStatus = !lampStatus; 
    
    digitalWrite(RELAY_PIN, lampStatus); // Mengubah status lampu sesuai toggle
    
    if (lampStatus == HIGH) {
      Serial.println("Lampu menyala karena suara terdeteksi");
    } else {
      Serial.println("Lampu mati karena suara terdeteksi");
    }
    
    delay(500); 
  }

  lastState = currentState;
}
