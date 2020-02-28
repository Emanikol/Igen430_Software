//microstepping pins 1
const int MS1 = 13;
const int MS2 = 12;
const int MS3 = 11;
//step is analog
const int stepPin = 10; 
//dir is digital
const int dirPin = 9; 

//microstepping pins 2
const int MS12 = 6;
const int MS22 = 5;
const int MS32 = 4;
//step is analog
const int stepPin2 = 3; 
//dir is digital
const int dirPin2 = 2;  

//higher the number, slower motor rotates
const int accelDelay = 500;

//higher the number, frequency of movements is slower
const int delayBetweenMovements = 500;

//microstepping scale const
const int microstep = 1;

//amount of positions to go to in x and y directions
const int arraySize = 4;

//vars to hold incoming message
String input;
int convertInput;
int movement;
 
void setup() {
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(MS1,OUTPUT);
  pinMode(MS2,OUTPUT);
  pinMode(MS3,OUTPUT);

  pinMode(stepPin2,OUTPUT); 
  pinMode(dirPin2,OUTPUT);
  pinMode(MS12,OUTPUT);
  pinMode(MS22,OUTPUT);
  pinMode(MS32,OUTPUT);

  digitalWrite(MS1,HIGH);
  digitalWrite(MS2,HIGH);
  digitalWrite(MS3,HIGH);

  digitalWrite(MS12,HIGH);
  digitalWrite(MS22,HIGH);
  digitalWrite(MS32,HIGH);

  Serial.begin(57600);
}

void loop() {
  //enabling all three microstepping pins --> 1/16th of a step --> 3200 steps is a full rotation
  while(Serial.available()>0)
  {
    input = Serial.readString();
    convertInput = input.toInt();

    if(convertInput = 1)
    {
      input = Serial.readString();
      movement = input.toInt();
      moveMotorX(movement);
    }
    else if(convertInput = 2)
    {
      input = Serial.readString();
      movement = input.toInt();
      moveMotorY(movement);
    }
  }
}

void moveMotorX(int movementX) {
  int constant = 1;
  int steps = abs(movementX*constant)*microstep;

  if(movementX > 0) {
    digitalWrite(dirPin,LOW); //spins CW
    for(int x = 0; x < steps; x++) {
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(accelDelay);
      digitalWrite(stepPin,LOW);
      delayMicroseconds(accelDelay);
    }
    delay(delayBetweenMovements);
    }
    
  else if (movementX < 0) {
    digitalWrite(dirPin,HIGH); //spins CCW
    for(int x = 0; x < steps; x++) {
      digitalWrite(stepPin,HIGH); 
      delayMicroseconds(accelDelay); 
      digitalWrite(stepPin,LOW); 
      delayMicroseconds(accelDelay);   
    }
    delay(delayBetweenMovements);
  }
   
}

void moveMotorY(int movementY) {
  int constant = 1;
  int steps = abs(movementY*constant)*microstep;

  if(movementY > 0) {
    digitalWrite(dirPin2,LOW); //spins CW
    for(int y = 0; y < steps; y++) {
      digitalWrite(stepPin2,HIGH);
      delayMicroseconds(accelDelay);
      digitalWrite(stepPin2,LOW);
      delayMicroseconds(accelDelay);
    }
    delay(delayBetweenMovements);
    }
    
  else if (movementY < 0) {
    digitalWrite(dirPin2,HIGH); //spins CCW
    for(int y = 0; y < steps; y++) {
      digitalWrite(stepPin2,HIGH); 
      delayMicroseconds(accelDelay); 
      digitalWrite(stepPin2,LOW); 
      delayMicroseconds(accelDelay);   
    }
    delay(delayBetweenMovements);
  }
   
}
