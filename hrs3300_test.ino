#include "Wire.h"
#include "HRS3300.h"
#include <BLEPeripheral.h>
#include "BLESerial.h"

#define DEBUG_PORT BLESerial
// required by BLE lib
#define BLE_REQ   -1
#define BLE_RDY   -1
#define BLE_RST   -1
BLESerial BLESerial(BLE_REQ, BLE_RDY, BLE_RST);
HRS3300 hrs;

void setup() {
  //Serial.begin(9600);  
  BLESerial.setLocalName("HBand");
  BLESerial.begin();
  Wire.begin();  
  hrs.initialize();
  Serial.println("HRS3300 HRS sensor test");
  Serial.print("Device ID: ");
  Serial.println(hrs.getDeviceID(), HEX);
  hrs.enableHRS(true);
}

void loop() {
  DEBUG_PORT.println(hrs.readHRS());
  delay(10);
}
