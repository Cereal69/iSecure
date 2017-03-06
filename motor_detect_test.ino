int triggerPin = 12;
int echoPin = 13;
int enA = 3;
int in1=4, in2=2;

void setup() {
  Serial.begin(9600); //we'll start serial comunication, so we can see the distance on the serial monitor Serial.println("Tech Ponder's UltraSonic Sensor Tutorial");
  pinMode(triggerPin,OUTPUT);
  pinMode(echoPin,INPUT);
  
  pinMode(enA,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  
}

void loop() {
  int duration, distance; //Adding duration and distance
  digitalWrite(triggerPin, HIGH); //triggering the wave(like blinking an LED)
  delay(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH); //a special function for listening and waiting for the wave
  distance = (duration/2) / 29.1;
  if(distance > 10)
  {
    digitalWrite(in2,HIGH);
    digitalWrite(in1,LOW);
    /* 10 seq*/
    analogWrite(enA,255);
  }
  else
  {
    analogWrite(enA,0);
  }
  delay(100);
}
