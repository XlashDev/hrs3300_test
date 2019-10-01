// NOTE: THIS IS ONLY A PARIAL RELEASE. THIS DEVICE CLASS IS CURRENTLY UNDERGOING ACTIVE
// DEVELOPMENT AND IS STILL MISSING SOME IMPORTANT FEATURES. PLEASE KEEP THIS IN MIND IF
// YOU DECIDE TO USE THIS PARTICULAR CODE FOR ANYTHING.

/* ============================================
I2Cdev device library code is placed under the MIT license
Copyright (c) 2012 Jeff Rowberg
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
===============================================
*/

#include  "HRS3300.h"

HRS3300::HRS3300(){
  devAddr = HRS3300_ADDRESS;
}

uint8_t HRS3300::getDeviceID() {
    I2Cdev::readByte(devAddr,HRS3300_ID,buffer);
    return buffer[0];
}
/** Enable and prepare for general usage.
 */
void HRS3300::initialize() {
  // initialize recommended values
  I2Cdev::writeByte(devAddr,HRS3300_RES, 0x66);  
  I2Cdev::writeByte(devAddr,HRS3300_HGAIN, 0x10);
  I2Cdev::writeByte(devAddr,HRS3300_PDRIVER, 0x68);
}

void HRS3300::enableHRS(boolean en_ctl){
  if(en_ctl){
    I2Cdev::writeByte(devAddr,HRS3300_ENABLE, 0xE8);
  }
  else{    
    I2Cdev::writeByte(devAddr,HRS3300_ENABLE, 0x68);
  }
}

uint16_t HRS3300::readHRS(){
  uint16_t hrs_data = 0x0;
  I2Cdev::readByte(devAddr,HRS3300_C0DATAM,buffer);  
  hrs_data = (buffer[0] & 0xFFFF) << 8;
  I2Cdev::readByte(devAddr,HRS3300_C0DATAH,buffer);    
  buffer[0] = buffer[0] << 4;  
  hrs_data |= buffer[0];  
  I2Cdev::readByte(devAddr,HRS3300_C0DATAL,buffer);  
  hrs_data |= buffer[0];   
  return hrs_data;
}

uint32_t HRS3300::readALS(){
  uint32_t als_data = 0x0;
  I2Cdev::readByte(devAddr,HRS3300_C1DATAH,buffer);
  als_data = buffer[0];  
  als_data = als_data << 8;
  I2Cdev::readByte(devAddr,HRS3300_C1DATAM,buffer);  
  als_data |= buffer[0];  
  I2Cdev::readByte(devAddr,HRS3300_C1DATAL,buffer);  
  als_data == als_data << 3;
  als_data |= buffer[0];   
  return als_data;
}
