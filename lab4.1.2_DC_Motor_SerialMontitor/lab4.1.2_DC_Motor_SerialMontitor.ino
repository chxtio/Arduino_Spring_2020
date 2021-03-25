//Upload this sketch and then open up the Serial Monitor. 
//Type in a value (0 - 255) and hit enter.
const int analogOutPin = 3; //motor is connected to pin 3
int motorSpeed = 0;

void setup()
{
  Serial.begin(9600); //initiate Serial communication
  Serial.println("Type in a value from 0 255 and hit enter.");
  pinMode(analogOutPin, OUTPUT);
}

void loop()
{
  if (Serial.available () > 1)
{
  motorSpeed = Serial.parseInt();
  Serial.print("Setting motor speed to: ");
  Serial.println(motorSpeed);
  analogWrite(analogOutPin , motorSpeed);
}
}
