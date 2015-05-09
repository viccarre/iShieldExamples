#include <boards.h>
#include "Boards.h"
#include <SPI.h>
#include <Nordic_nRF8001.h>
#include <RBL_nRF8001.h>
#include "iShield.h"
#include "Adafruit_SoftServo.h"


#define SERVO1PIN 5
#define SERVO2PIN 3

Adafruit_SoftServo servo_left, servo_rght;

iShield myiShield;
	
void setup()
{
  	// Init. and start BLE library.
	ble_begin();
  	Serial.begin(9600); 
  	servo_left.attach(SERVO1PIN);
	servo_rght.attach(SERVO2PIN);
}

void loop()
{
	myiShield.getInbox();
	  	
	if(myiShield.isAPressed() == true){
		//Go Forwar
        Serial.println("true, Up pressed");
        servo_left.write(180);
	  	servo_left.refresh();
	  	delay(15);
	  	servo_rght.write(0);
	  	servo_rght.refresh();
	  	delay(15);
        
    }
    if(myiShield.isDownPressed() == true){
        Serial.println("true, Down pressed");
         //Go Backward
	    servo_left.write(0);
	  	servo_left.refresh();
	  	delay(15);
	  	servo_rght.write(180);
	  	servo_rght.refresh();
	  	delay(15);
	  	
    }
    if(myiShield.isLeftPressed() == true){
        Serial.println("true, Left pressed");
      	//Go Left
      	
	    servo_left.write(0);
	  	servo_left.refresh();
	  	delay(15);
	  	servo_rght.write(0);
	  	servo_rght.refresh();
	  	delay(15);
    }
    if(myiShield.isRightPressed() == true){
        Serial.println("true, Right pressed");
      	//Go Right

	    servo_left.write(180);
	  	servo_left.refresh();
	  	delay(15);
	  	servo_rght.write(180);
	  	servo_rght.refresh();
	  	delay(15);
    }
	  
}