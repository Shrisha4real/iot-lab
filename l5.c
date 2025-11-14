#define LDR 32
#define BUZZER_PIN 23
#define LIGHT_THRESHOLD 500
void setup() {
	Serial.begin(9600);
	pinMode(LDR, INPUT);
	pinMode(BUZZER_PIN, OUTPUT);
	digitalWrite(BUZZER_PIN, LOW);
}
void loop() {
	int sensorValue = analogRead(LDR);
	Serial.print("LDR Level: ");
	Serial.println(sensorValue);
	if (sensorValue <
		LIGHT_THRESHOLD) {
		Serial.println("Low Light Detected -
		Buzzer ON");
		digitalWrite(BUZZER_PIN, HIGH);
	} else {
		digitalWrite(BUZZER_PIN, LOW);

	}
	delay(500);


}
