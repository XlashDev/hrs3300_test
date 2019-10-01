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

#ifndef _HRS3300_H_
#define _HRS3300_H_

#include "I2Cdev.h"

#define HRS3300_ADDRESS             0x44

// address and recommended value
#define HRS3300_ID                  0x00 //Device ID (0x21) RO
#define HRS3300_ENABLE              0x01 //Enable HRS (0x68) R/W
#define HRS3300_C1DATAM             0x08 //CH1 data reg bit 10~3 (0x00) RO
#define HRS3300_C0DATAM             0x09 //CH0 data reg bit 15~8 (0x00) RO
#define HRS3300_C0DATAH             0x0A //CH0 data reg bit 7~3 (0x00) RO
#define HRS3300_PDRIVER             0x0C //HRS LED driver/PON/PDRIVE[0] (0x68) R/W
#define HRS3300_C1DATAH             0x0D //CH1 data reg but 17~11 (0x00) RO
#define HRS3300_C1DATAL             0x0E //CH1 data reg bit 2~0 (0x00) RO
#define HRS3300_C0DATAL             0x0F //CH1 data reg bit 17~16 and 3~0 (0x00) RO
#define HRS3300_RES                 0x16 //ALS and HRS resolution (0x66) (R/W)
#define HRS3300_HGAIN               0x17 //HRS Gain (0x10) (R/W)

class HRS3300 {
  public:
    HRS3300();
      
    uint8_t getDeviceID();
    void initialize();    
    void enableHRS(boolean en_ctl);
    uint16_t readHRS();
    uint32_t readALS();    
  private:
    uint8_t devAddr;
    uint8_t buffer[14];
};

#endif /* _HRS3300_H_ */
