#include <EMduino.h>
#include <SPI.h>
#include "RF24.h"
#include "Narcoleptic.h"
#include "Volume.h"

EMduino port("send");
Volume container(7, 8);

void setup() {
  Serial.begin(115200);
  port.setupRadio();
  container.setCylinder( 6 /* radius in meters */ , 55 /* height in meters */ );
}
void loop() {
  port.setPacketContent(container.getVolume());
  Serial.print("the volume in cc is.. ");
  Serial.println(container.getVolume());
  port.write();
}
