#include "PMS.h"

PMS pms(Serial);
PMS::DATA data;

void setup()
{
  Serial.begin(9600);   // GPIO1, GPIO3 (TX/RX pin on ESP-12E Development Board)
  Serial1.begin(9600);  // GPIO2 (D4 pin on ESP-12E Development Board)
}

uint16_t previousChecksum;

void loop()
{
  if (pms.read(data))
  {
    if (previousChecksum == data.checksum) {
      Serial1.println("checksum did ot change since previous read probably a duplicate");
    }

    Serial1.print("PM 1.0 (ug/m3): ");
    Serial1.println(data.PM_AE_UG_1_0);

    Serial1.print("PM 2.5 (ug/m3): ");
    Serial1.println(data.PM_AE_UG_2_5);

    Serial1.print("PM 10.0 (ug/m3): ");
    Serial1.println(data.PM_AE_UG_10_0);

    Serial1.println();
    
    previousChecksum = data.checksum;
  }

  // Do other stuff...
}