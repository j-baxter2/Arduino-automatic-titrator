//Define colour sensor pins 

#define S0 3
#define S1 4
#define S2 5
#define S3 6
#define LED 7
#define sensorOut 2

//Variables for Colour Pulse Width measurement

int redPW = 0;
int greenPW = 0;
int bluePW = 0;

void setup() {
  
  //Set S0 - S3 as outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(LED, OUTPUT);

  //Turn on LED
  digitalWrite(LED, HIGH);
  
  //Set Sensor output as input
  pinMode(sensorOut, INPUT);

  //Set Pulse Width scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  //Setup Serial Monitor
  Serial.begin(9600);
}

void loop() {
  //Read Red Pulse Width
  redPW = getRedPW();
  //Delay to stabilise sensor
  delay(200);

  //Read Green Pulse Width
  greenPW = getGreenPW();
  //Delay to stabilise sensor
  delay(200);

  //Read Blue Pulse Width
  bluePW = getBluePW();
  //Delay to stabilise sensor
  delay(200);

  //Print output to Serial Monitor
  Serial.print("Red PW = ");
  Serial.print(redPW);
  Serial.print(" - Green PW = ");
  Serial.print(greenPW);
  Serial.print(" - Blue PW = ");
  Serial.print(bluePW);
  Serial.print('\n');
  
}

//Function to read Red Pulse Widths
int getRedPW() {

  //Set sensor to read Red only
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  //Define integer to represent
  int PW;
  //Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  //Return the value
  return PW;
}

//Function to read Green Pulse Widths
int getGreenPW() {

  //Set sensor to read Green only
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  //Define integer to represent
  int PW;
  //Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  //Return the value
  return PW;
}

//Function to read Blue Pulse Widths
int getBluePW() {

  //Set sensor to read Blue only
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  //Define integer to represent
  int PW;
  //Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  //Return the value
  return PW;
}
