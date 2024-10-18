#define trigPin 3 
#define echoPin 2 
int Watersensor = 4;
int Buzzer = 12; 
int led = 13; 

void setup() 
{ 
  Serial.begin(9600); // set your baud 
  rate pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(Watersensor,INPUT); 
  pinMode(Buzzer,OUTPUT); 
  pinMode(led,OUTPUT); 
} 

void loop() 
{ 
  Serial.print(ultrasonic()); 
  int WS = digitalRead(Watersensor); 
  
  if(WS == LOW) 
  { 
    digitalWrite(Buzzer,HIGH);
    delay(30); 
    digitalWrite(Buzzer,LOW); 
    delay(100); 
  } 
    else if(ultrasonic() < 15) 
    { 
      digitalWrite(Buzzer,HIGH); 
      //delay(1000); 
    } 
    else if ( ultrasonic() > 15 || WS == HIGH ) 
    { 
      digitalWrite(Buzzer,LOW);
      //digitalWrite(led,LOW); 
    } 
  
  } 
  int ultrasonic() 
  { 
    long duration, distance;
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW); 
    duration = pulseIn(echoPin, HIGH); 
    distance = (duration/2) / 29.1; 
    Serial.println(distance); 
    delay(30); 
    return distance;
  }