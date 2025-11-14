const int trigPin = 26;
const int echoPin = 25;
const int buzzerPin = 23; // Buzzer connected to GPIO 27 (you can change it)
// Define sound speed in cm/uS
#define SOUND_SPEED 0.0343
#define CM_TO_INCH 0.393701
long duration;
float distanceCm;
float distanceInch;
void setup() {
	Serial.begin(9600); // Starts serial communication
	pinMode(trigPin, OUTPUT); // Sets the trigPin as Output
	pinMode(echoPin, INPUT); // Sets the echoPin as Input
	pinMode(buzzerPin, OUTPUT); // Sets the buzzerPin as Output
}
void loop() {
// Clears the trigPin
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);

	// Sets the trigPin HIGH for 10 microseconds
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);

	// Reads echoPin, returns sound wave travel time in microseconds
	duration = pulseIn(echoPin, HIGH);

	// Calculate the distance (cm)
	distanceCm = duration * SOUND_SPEED / 2;

	// Convert to inches
	distanceInch = distanceCm * CM_TO_INCH;

	// Print distance on Serial Monitor
	Serial.print("Distance (cm): ");
	Serial.println(distanceCm);
	Serial.print("Distance (inch): ");
	Serial.println(distanceInch);

	// Buzzer condition
	if (distanceCm < 10 && distanceCm > 0) { // Object is very close
		digitalWrite(buzzerPin, HIGH); // Turn buzzer ON
		Serial.println(" Object detected nearby! Buzzer ON");
	} else {
		digitalWrite(buzzerPin, LOW); // Turn buzzer OFF
		Serial.println("No nearby object. Buzzer OFF");
	}
	Serial.println("--------------------------");
	delay(1000);
}
