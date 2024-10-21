int S0 = 4;
int S1 = 5;
int S2 = 6;
int S3 = 7;
int sensorOut = 8;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  unsigned long redPW = pulseIn(sensorOut, LOW);
  delay(200);
  
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  unsigned long greenPW = pulseIn(sensorOut, LOW);
  delay(200);
  
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  unsigned long bluePW = pulseIn(sensorOut, LOW);
  delay(200);

  
  Serial.print("R: ");
  Serial.print(redPW);
  Serial.print(" G: ");
  Serial.print(greenPW);
  Serial.print(" B: ");
  Serial.println(bluePW);
  
  delay(500);
}
