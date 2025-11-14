#define TRIG_PIN 26
#define ECHO_PIN 25
#define BUZZER_PIN 23 // Optional: buzzer or LED
#define DISTANCE_THRESHOLD 10 // in cm
void setup() {
	 Serial.begin(115200);
	 pinMode(TRIG_PIN, OUTPUT);
	 pinMode(ECHO_PIN, INPUT);
	 pinMode(BUZZER_PIN, OUTPUT);
	 digitalWrite(BUZZER_PIN, LOW);
}
	void loop() {
	 float distance = getDistance();
	 Serial.print("Distance: ");
	 Serial.print(distance);
	 Serial.println(" cm");
	 if (distance > 0 && distance < DISTANCE_THRESHOLD) {
		 Serial.println(" Intrusion Detected!");
	 digitalWrite(BUZZER_PIN, HIGH);
	 } else {
		 digitalWrite(BUZZER_PIN, LOW);
	 }
	 delay(500);
}
float getDistance() {
	digitalWrite(TRIG_PIN, LOW);
	delayMicroseconds(2);
	digitalWrite(TRIG_PIN, HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIG_PIN, LOW);
	long duration = pulseIn(ECHO_PIN, HIGH, 30000); // Timeout 30ms (~500cm)
	if (duration == 0) {
		return -1; // Timeout or no object
	}
	float distance = duration * 0.034 / 2;
	return distance;
}
