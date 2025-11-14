int leds[] = {27,26,25,33}; // Assign pins for the LEDs
int numLEDs = 4;
 int delayTime = 200; // Delay between LED changes in milliseconds
int direction = 1; // 1 for forward, -1 for backward
int currentLED = 0;
void setup() {
	for (int i = 0; i < numLEDs; i++) {
		pinMode(leds[i], OUTPUT);
	}
}
void loop() {
	// Turn off all LEDs
	for (int i = 0; i < numLEDs; i++) {
		digitalWrite(leds[i], LOW);
}
// Turn on the current LED
digitalWrite(leds[currentLED], HIGH);
delay(delayTime);
// Update the current LED index, reversing direction if needed
currentLED += direction;
if (currentLED >= numLEDs - 1 || currentLED <= 0) {
	direction *= -1; // Reverse direction
}
}
