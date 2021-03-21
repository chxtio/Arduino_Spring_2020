int redPin = 5;
int greenPin = 6;
int bluePin = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(redPin, 255);
  analogWrite (greenPin, 255);
  analogWrite (bluePin, 255);
  delay (1000);
  analogWrite(redPin, 255);
  analogWrite (greenPin, 0);
  analogWrite (bluePin, 0);
 delay(1000);
  analogWrite(redPin, 0);
  analogWrite (greenPin, 255);
  analogWrite (bluePin, 0);
 delay(1000);
   analogWrite(redPin, 0);
  analogWrite (greenPin, 0);
  analogWrite (bluePin, 255);
}
