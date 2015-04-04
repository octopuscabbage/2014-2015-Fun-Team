#include <RedBot.h>
#include <RedBotSoftwareSerial.h>

RedBotSoftwareSerial mySerial = SoftwareSerial(A0, A1); // RX, TX
//Receiver Board - Just gets motor commands

void setup()  
{
  int RED, YELLOW, GREEN;
  RED = A5;
  YELLOW = 10;
  GREEN = 11;
  RedBotMotors motor;
  // Open serial communications and wait for port to open:
  mySerial.begin(38400);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() // run over and over
{

  int incoming = mySerial.available;

  if (incoming > 0)
  {
      switch(incoming) {
       case 1:
       {
         //FullStop
         motor.stop;
         break;
       }
       case 2:
       {
         //RedOn
         digitalWrite(RED, HIGH);
         break;
       }
       case 3:
       {
         //YellowOn
         digitalWrite(YELLOW, HIGH);
         break;
       }
       case 4:
       {
         //GreenOn
         digitalWrite(GREEN, HIGH);
         break;
       }
       case 5:
       {
         //RedOff
         digitalWrite(RED, LOW);
         break;
       }
       case 6:
       {
         //YellowOff
         digitalWrite(YELLOW, LOW);
         break;
       }
       case 7:
       {
         //GreenOff
         digitalWrite(GREEN, LOW);
         break;
       }
       case 8:
       {
         //GoForward
         motor.drive(255);
         break;
       }
       case 9:
       {
         //TurnRight
         motor.leftDrive(255);
         motor.rightDrive(-255);
         break;
       }
       case 10:
       {
         //TurnLeft
         motor.leftDrive(-255);
         motor.rightDrive(255);
         break;
       }
      }
  }
 }