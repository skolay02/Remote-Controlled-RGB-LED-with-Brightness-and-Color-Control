#include <IRremote.h>

int IRpin=9;

IRrecv IR(IRpin);
decode_results cmd;

String mycom;

int rpin=6;			//red
int gpin=10;		//green
int bpin=5;		//blue

int rbright=255;
int gbright=255;
int bbright=255;

float dfact=1;		//Dim factor that determines dimness of the led

void setup()
{
  Serial.begin(9600);
  IR.enableIRIn();
  
  pinMode(rpin,OUTPUT);
  pinMode(gpin,OUTPUT);
  pinMode(bpin,OUTPUT);
}

void loop()
{
  while(IR.decode(&cmd)==0)		//while the reciever recieves command from the remote
  {
  }
  
  delay(1500);
  IR.resume();					//Reads the next command from the remote
  
  //Assigning the hex values to the buttons ont remote
  //[Note: These values varies from remote to remote. Read the hex code from ur remote for a particular button before proceeding further.]
  
          if(cmd.value=0xFF6897)		//0
          {
            mycom="zero";
            Serial.println(mycom);
          }

          if(cmd.value=0xFF30CF)		//1
          {
            mycom="one";
            Serial.println(mycom);
          }

          if(cmd.value=0xFF18E7)		//2
          {
            mycom="two";
            Serial.println(mycom);
          }

          if(cmd.value=0xFF7A85)		//3
          {
            mycom="three";
            Serial.println(mycom);
          }

          if(cmd.value=0xFF10EF)		//4
          {
            mycom="four";
            Serial.println(mycom);
          }

          if(cmd.value=0xFF38C7)		//5
          {
            mycom="five";
            Serial.println(mycom);
          }

          if(cmd.value=0xFF5AA5)		//6
          {
            mycom="six";
            Serial.println(mycom);
          }

          if(cmd.value=0xFFA25D)		//Power
          {
            mycom="power";
            Serial.println(mycom);
          }

          if(cmd.value=0xFFE21D)		//Function
          {
            mycom="function";
            Serial.println(mycom);
          }

          if(cmd.value=0xFFE01F)		//Down
          {
            mycom="down";
            Serial.println(mycom);
          }

          if(cmd.value=0xFF906F)		//Up
          {
            mycom="up";
            Serial.println(mycom);
          }
  
  
  //Assigning the buttons to the respective colours
  if(mycom=="pwr")		//ON
  {
    rbright=255;
    gbright=255;
    bbright=255;
    dfact=1;
  }
  
  if(mycom=="function")	//OFF
  {
    rbright=0;
    gbright=0;
    bbright=0;
    dfact=0;
  }
  
  if(mycom=="zero")		//0 - white
  {
    rbright=255;
    gbright=255;
    bbright=255;
  }
  
  if(mycom=="one")		//1 - red
  {
    rbright=255;
    gbright=0;
    bbright=0;
  }
  
  if(mycom=="two")		//2 - green
  {
    rbright=0;
    gbright=255;
    bbright=0;
  }
  
  if(mycom=="three")		//3 - blue
  {
    rbright=0;
    gbright=0;
    bbright=255;
  }
  
  if(mycom=="four")		//4 - cyan=green+blue
  {
    rbright=0;
    gbright=255;
    bbright=255;
  }
  
  if(mycom=="five")		//5 - magenda=red+blue
  {
    rbright=255;
    gbright=0;
    bbright=150;
  }
  
  if(mycom=="six")		//6 - yellow=red+green
  {
    rbright=255;
    gbright=255;
    bbright=0;
  }
  
  
  //Determining the dimness and brightness of the led
  if(mycom=="down")
  {
    dfact=dfact*0.75;
  }
  
  if(mycom=="up")
  {
    dfact=dfact*1.3;
    if(dfact>1)
    {
      dfact=1;
    }
  }
    
  
  analogWrite(rpin,rbright*dfact);
  analogWrite(gpin,gbright*dfact);
  analogWrite(bpin,bbright*dfact);
}