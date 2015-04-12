#include "Boards.h"
#include <SPI.h>
#include <Nordic_nRF8001.h>
#include <RBL_nRF8001.h>
#include "iShield.h"
#include "DHT.h"

#define DHTPIN 2 
#define DHTTYPE DHT11

iShield myiShield;
DHT dht(DHTPIN, DHTTYPE);
	
void setup()
{
  	// Init. and start BLE library.
	ble_begin();
  	Serial.begin(9600); 
  	ble_set_name("BLEShield");
 
 	//Init the dth 
  	Serial.println("DHTxx test!");
	dht.begin();
}

void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(t) || isnan(h)) {
    Serial.println("Error at reading the weather sensor");
  } else {
	
	//Sending data to iOS Device
	myiShield.setTemperature(t);
    myiShield.setHumidity(h);
    
  }
  
}