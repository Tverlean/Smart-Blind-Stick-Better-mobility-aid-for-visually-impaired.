//Conditions:
//FOR ULTRASONIC SENSOR(responsible for detecting obstacles)
  //When the the distance of the obstacle from ultrasonic sensor is less than or equal to 50cm:
  //the buzzer with tone of 300 runs continously.
  //the distance shows at serial monitor.
  //RGB turns Red.
 
//FOR LDR(responsible for making a cue whenever the user is in a dark place)
  //When the intensity of light is less than or equals to 200:
  //the buzzer with the tone of 500 runs with delay.
  //"Low Light" print on serial monitor.
  //RGB turns Blue.
  
//FOR MOISTURE SENSOR(alter for watersonsor; to give a cue to the user whenever he/she is on wet area or in any water surface)
  //When the moisture value is greater than or equals to 50%:
  //the buzzer with 1200 tone runs with delay.
  //the moisture value shows at serial monitor.
  //RGB turns Green.
   
int redPin=3;
int bluePin=5;
int greenPin=6;
int moistureValue;
float moisture_percentage;
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int Light = A5;

long duration;
int distance;
int safetyDistance;
int Intens;
int safetyIntens;

void setup () {
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(buzzer, OUTPUT);
  pinMode(Light, INPUT);
  Serial.begin(9600); // Starts the serial communication
  
}

void loop() {
  moistureValue=analogRead(A4);
  moisture_percentage=((moistureValue/539.00)*100);
  Serial.print("\nMoisture Value:");
  Serial.print(moisture_percentage);
  Serial.println("%");
  delay(1000);
  if (moisture_percentage >= 50)
  {
   digitalWrite(redPin,LOW);
   digitalWrite(bluePin,LOW);
   digitalWrite(greenPin,HIGH);
   tone(11,1500);
   delay(300);
   noTone(11);
  }
  else
  {
    noTone(11);
  }
  
 Intens = analogRead(Light);
  safetyIntens = Intens;
  if (safetyIntens <= 200){
  //If very dark
  digitalWrite(redPin,LOW);
  digitalWrite(bluePin,HIGH);
  digitalWrite(greenPin,LOW);
  Serial.print("Low Light:");
  Serial.println(Intens); 
  tone(11,500);
  delay(500);
   noTone(11);
  }
 
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
   duration = pulseIn(echoPin, HIGH)

  // Calculating the distance
  ;distance= duration*0.034/2;

  safetyDistance = distance;
  if (safetyDistance <= 50){
    tone(11,300);
    digitalWrite(redPin,HIGH);
    digitalWrite(bluePin,LOW);
    digitalWrite(greenPin,LOW);
  }
  else {
    noTone(11);
  }
{
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
}
  }
