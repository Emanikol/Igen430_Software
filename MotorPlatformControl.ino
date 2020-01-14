/*    
 * Note: accel func, speed
 */
// defines pin numbers for motor1
const int stepPin1 = 3; 
const int dirPin1 = 2; 
const int MS1_1 = 4;
const int MS2_1 = 5;
const int MS3_1 = 6;

//defines pin numbers for motor2
const int stepPin2 = 8;
const int dirPin2 = 9; 
const int MS1_2 = 10;
const int MS2_2 = 11;
const int MS3_2 = 12;

//higher the number, slower motor rotates
const int accelDelay = 500;

//microstepping scale const
const int microstep = 16;
 
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin1,OUTPUT); 
  pinMode(dirPin1,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //enabling all three microstepping pins --> 1/16th of a step
  digitalWrite(MS1_1,HIGH);
  digitalWrite(MS2_1,HIGH);
  digitalWrite(MS3_1,HIGH);
  
  int xMin = 0;
  int xMax = 100;
  
  int yMin = 0;
  int yMax = 100;

  //Currently have to seperate x and y components of a coordinate... need to look into this
  int x[] = {5, 3, 50, 20, 70};
  int y[] = {5, 3, 50, 20, 70};

  for(int i = 0; i < 5; i++) {
    if(x[i] < xMin || x[i] > xMax) {
      Serial.print("ERROR: One of the coordinates are out of bounds");
      while(1);
    }
    if(y[i] < yMin || y[i] > yMax) {
      Serial.print("ERROR: One of the coordinates are out of bounds");
      while(1);
    }
  }
  
  goToX(x);
  goToY(y);

  while(1);
}

void goToX(int x[]) {
  int currentX = 0;
//  Serial.print("Starting coordinates: (0,0)");
//  Serial.print('\n');

  //How to find size for array...??? For now using 5
  for(int i = 0; i < 5; i++){
    int movementX = x[i] - currentX;
    moveMotorX(movementX);
    currentX = x[i];
    Serial.print(movementX);
//    Serial.print('\n');
//    Serial.print("New coordinate: ("); Serial.print(currentX); Serial.print(",0)");
//    Serial.print('\n');
  }

}

void moveMotorX(int movementX) {
  int constant = 1;
  int steps = abs(movementX*constant)*microstep;

  if(movementX > 0) {
    turnMotor1OneStepCW(steps);
    Serial.print("Move x forwards: ");
  }
  else if (movementX < 0) {
    turnMotor1OneStepCCW(steps);
    Serial.print("Move x backwards: ");
  }
   
}


void goToY(int y[]) {
  int currentY = 0;

  //How to find size for array...??? For now using 5
  for(int i = 0; i < 5; i++){
    int movementY = y[i] - currentY;
    moveMotorY(movementY);
    currentY = y[i];
    Serial.print(movementY);
  }

}

void moveMotorY(int movementY) {
  int constant = 1;
  int steps = abs(movementY*constant)*microstep;

  if(movementY > 0) {
    turnMotor2OneStepCW(steps);
    Serial.print("Move y forwards: ");
  }
  else if (movementY < 0) {
    turnMotor2OneStepCCW(steps);
    Serial.print("Move y backwards: ");
  }
   
}



//Insert code for motorY (same as motorX), only working with one motor for one

//These functios control the direction of x/y movements
void turnMotor1OneStepCCW(int steps) {
  digitalWrite(dirPin1,HIGH); // Enables the motor to move in a particular direction 
  // Make one pulse that turns the motor 1.8 degrees in the specified direction
  for(int x = 0; x < steps; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(accelDelay); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(accelDelay);   
  }
  delay(1000); // One second delay
}

void turnMotor1OneStepCW(int steps) {
  digitalWrite(dirPin1,LOW); //Changes the rotations direction
  // Makes one pulse that turns the motor 1.8 degrees in the specified direction
  for(int x = 0; x < steps; x++) {
    digitalWrite(stepPin1,HIGH);
    delayMicroseconds(accelDelay);
    digitalWrite(stepPin1,LOW);
    delayMicroseconds(accelDelay);
  }
  delay(1000);
}

//These functios control the direction of x/y movements
void turnMotor2OneStepCCW(int steps) {
  digitalWrite(dirPin2,HIGH); // Enables the motor to move in a particular direction 
  // Make one pulse that turns the motor 1.8 degrees in the specified direction
  for(int x = 0; x < steps; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(accelDelay); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(accelDelay);   
  }
  delay(1000); // One second delay
}

void turnMotor2OneStepCW(int steps) {
  digitalWrite(dirPin2,LOW); //Changes the rotations direction
  // Makes one pulse that turns the motor 1.8 degrees in the specified direction
  for(int x = 0; x < steps; x++) {
    digitalWrite(stepPin2,HIGH);
    delayMicroseconds(accelDelay);
    digitalWrite(stepPin2,LOW);
    delayMicroseconds(accelDelay);
  }
  delay(1000);
}

