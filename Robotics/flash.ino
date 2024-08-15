/* 

This is code for a "Key system" that uses an LED and LDR.

Combined code--using one arduino to illustrate the concept...
*/

#include <Servo.h> //library for servo


Servo doorlock; //the servo is named doorlock

int pos=0;
int count = 0;//sequence count
int flash = 0;//flash count
int dark = 0;//dark count

char code[] = {'0','0','0','0','0'};

#define LED_KEY_PIN 6 //The LED is connected to pin 6 on the arduino board
#define BUTTON_PIN 7  //The pushbutton is connected to pin 7 on the arduino board


void setup() {
  pinMode(LED_KEY_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);

  doorlock.attach(9);  //the servo is connected 

  doorlock.write(0);   //all this is just checking the servo
  delay(500);
  doorlock.write(20);
  delay(500);
  doorlock.write(0);

  Serial.begin(9600);



}

void loop() {

  int value = analogRead(A0);
  

if (digitalRead(BUTTON_PIN) == LOW){
     
     
     digitalWrite(LED_KEY_PIN, HIGH);
     delay (50);
     digitalWrite(LED_KEY_PIN, LOW);
     
     flash++;
     Serial.println("*");
     Serial.println(flash);
     delay(300);
     /*
     code[count-1] = flash;

    
     

     Serial.println("+"); 
     Serial.println(code);

     delay(200);


    if(flash == 6){
      flash = 0;
      Serial.println("Restart");
      for(int i = 0; i < 6; i++)
      {
        Serial.println(code[i]);
      }
      delay(2000);
  
    }*/
     
  }

else {
  
  dark++;
  if(dark > 15){dark = 0;}
  Serial.print("-");
  Serial.print(dark);
  delay(200);

}


///KEY/////

if (flash>1 && flash <10){

  Serial.println("Start Sequence");
  delay(1000);
  
}

else {
  flash =0;
  Serial.println("Start Sequence");
  delay(2000);
}
}
