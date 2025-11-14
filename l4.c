#define PB 21 //Push Button pin no GPIO 15
#define RELAY 12 //Relay pin no GPIO 2
void setup() {
// put your setup code here, to run once:
	Serial.begin(9600);
	pinMode(PB,INPUT);
	pinMode(RELAY,OUTPUT);
}
void loop() {
// put your main code here, to run repeatedly:
	int pb = digitalRead(PB);
	Serial.println(pb);
	if (pb==0){
		digitalWrite(RELAY,HIGH);
	}
	else{
		digitalWrite(RELAY,LOW);
	}
}
