//accelerometer arduino sketch for Laundry Web Service program. Outputs a line with three integer separated by spaces.
//ex. 123 123 123 , represents the acceleration felt in x, y and z axes respectively
//Based on sketch by David A. Mellis(2 Jul 2008). Modified by Bidit Sharma (25 Apr. 2016) for Laundry Web Service Project. 

// these constants describe the pins. 
const int groundpin = 18;             // analog input pin 4 -- ground
const int powerpin = 19;              // analog input pin 5 -- voltage
const int xpin = A3;                  // x-axis of the accelerometer
const int ypin = A2;                  // y-axis
const int zpin = A1;                  // z-axis (only on 3-axis models)
const int ledpin=13;                 //led pin

void setup() {
  // initialize the serial communications:
  Serial.begin(9600);

  // Provide ground and power by using the analog inputs as normal
  // digital pins.  This makes it possible to directly connect the
  // breakout board to the Arduino.  If you use the normal 5V and
  // GND pins on the Arduino, you can remove these lines.
  pinMode(groundpin, OUTPUT);
  pinMode(powerpin, OUTPUT);
  digitalWrite(groundpin, LOW);
  digitalWrite(powerpin, HIGH);
}
void loop(){
    Serial.print(analogRead(xpin));
    Serial.print(" ");
    Serial.print(analogRead(ypin));
    Serial.print(" ");
    Serial.print(analogRead(zpin));
    Serial.print("\n");
}
