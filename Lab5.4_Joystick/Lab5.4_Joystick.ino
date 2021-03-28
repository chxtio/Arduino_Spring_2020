
#define joyX A0
#define joyY A1

int xVal = 0;
int yVal = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
xVal = analogRead(joyX);
yVal = analogRead(joyY);

  Serial.print(xVal);
  Serial.print("\t");
  Serial.print(yVal);
  Serial.print("\n");
  delay(1000);
}
