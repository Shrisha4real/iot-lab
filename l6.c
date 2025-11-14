int soil_pin = 27;
void setup() {
	 pinMode(soil_pin, INPUT);
	 Serial.begin(9600);
}
void loop() {
	int moisture_value = analogRead(soil_pin); // Read analog value (0–4095 for ESP32)

	// Calibration values (adjust based on your sensor readings)
	int dryValue = 4095; // Sensor value when in air / dry waste
	int wetValue = 1200; // Sensor value when in wet waste (moist)

	// Convert to percentage (0 = dry, 100 = wet)
	int moisture_percent = map(moisture_value, dryValue, wetValue, 0, 100);
	moisture_percent = constrain(moisture_percent, 0, 100);
	Serial.print("Sensor Reading: ");
	Serial.println(moisture_value);
	Serial.print("Moisture Percentage: ");
	Serial.print(moisture_percent);
	Serial.println("%");
	// Threshold to classify wet/dry waste
	int threshold = 3000; // Adjust based on testing
	if (moisture_value > threshold) {
		Serial.println("Detected: DRY WASTE (Low moisture content)");
	} else {
		Serial.println("Detected: WET WASTE (High moisture content)");
	}
	Serial.println("--------------------------");
	delay(1000);
	}
