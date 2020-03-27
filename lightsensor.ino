// ------------
// Light Sensor
// ------------


// Variables

int led1 = D7; //On board LED
int photoresistor = A0; //Photoresistor analog signal connected to A0
int analogValue; // To store light value

//Setup

void setup() {

  pinMode(led1, OUTPUT);//led1 is an output
  pinMode(photoresistor, INPUT);//photoresistor is an input

}

//Main Loop
void loop() {

analogValue = analogRead(photoresistor);//store light value in variable

//If light is brighter than threshold LED is off. Otherwise LED is on.
if (analogValue > 2000) {
    digitalWrite (led1, LOW);
} else {
    digitalWrite (led1, HIGH);
}

String analogValue = String(analogRead(photoresistor)); //store light value as a string
Particle.publish("light", analogValue, PRIVATE); // publish light value data to webhook

delay(30000);//wait 30 sec

}

