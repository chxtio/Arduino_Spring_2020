//Control the DC motor speed with a potentiometer
const int analogInPin = A0; //potentiometer is connected to A0
const int analogOutPin = 3; //motor is connected to pin 3
int sensorValue = 0;
int outputValue = 0;

void setup()
{
Serial.begin(9600); //initialize serial communication at 9600 bps
}

void loop()
{
    sensorValue = analogRead(A0);
    outputValue = map(sensorValue, 0, 1023, 0, 255);
    analogWrite(analogOutPin,outputValue);

    Serial.print("sensor = ");
    Serial.println(sensorValue);
    //wait 2 ms to allow the analog-to-digital converter to settle 
    //after the last reading
    
    delay(2); 

}
