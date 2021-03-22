/*
  Adopted from: Arduino Starter Kit example Project 3 - Love-O-Meter
  This program uses a thermistor to control three LEDs. As the temperature 
  sensed by the thermistor increates, more LEDs turn on.
  http://www.arduino.cc/starterKit

*/

// named constant for the pin the sensor is connected to
const int sensorPin = A0;
// room temperature in Celsius
const float baselineTemp = 21.0;

void setup() {
  // open a serial connection to display values
  Serial.begin(9600);
  // set the LED pins as outputs
  // the for() loop saves some extra coding
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // read the value on AnalogIn pin 0 and store it in a variable
  int ADCReading = analogRead(sensorPin);

  // send the 10-bit sensor value out the serial port
  Serial.print("sensor Value: ");
  Serial.print(ADCReading);

  // convert the ADC reading to voltage
  float voltage = (ADCReading / 1024.0) * 5.0;

  // Send the voltage level out the Serial port
  Serial.print(", Volts: ");
  Serial.print(voltage);

  //Find the resistance of the thermistor
  long Resistance = 10000.0 * ((1024.0 / ADCReading - 1));
  //Find the temperature based on Steinhart–Hart equation
  float TempK = log(Resistance);
  TempK = 1 / (0.001129148 + 0.000234125 * TempK + 0.0000000876741 * TempK * TempK * TempK );

  float TempC = TempK - 273.15;            // Convert Kelvin to Celcius
  float TempF = (TempC * 9.0) / 5.0 + 32.0; // Convert Celcius to Fahrenheit

  Serial.print(", degrees C: ");
  Serial.println(TempC);
  // if the current temperature is lower than the baseline turn off all LEDs
  if (TempC < baselineTemp + 2) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } // if the temperature rises 2-4 degrees, turn an LED on
  else if (TempC >= baselineTemp + 2 && TempC < baselineTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } // if the temperature rises 4-6 degrees, turn a second LED on
  else if (TempC >= baselineTemp + 4 && TempC < baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } // if the temperature rises more than 6 degrees, turn all LEDs on
  else if (TempC >= baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1);
}
