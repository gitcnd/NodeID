/*
  NodeID.h v1.0 - Get (and initially set) a unique serial-number identity from EEPROM for each of your MCU boards (so the same code running on many different boards knows how to differentiate itself from the others)
  (C) Copyright 2018 (GNU GENERAL PUBLIC LICENSE, Version 3) - Chris Drake <cdrake@cpan.org>
*/

#ifndef NodeID_h
#include "Arduino.h"
#include "NodeID.h"
#include <EEPROM.h>     // for saving settings (SD card data file name) etc.

NodeID::NodeID(unsigned int eeprom_memory_offset_byte)
{
  _memloc=eeprom_memory_offset_byte;
}

unsigned int NodeID::get() {	// NB: teensy unsigned int is 4 bytes...
#ifdef ARDUINO_ESP8266_NODEMCU // Wemos_D1_ESP8266_NodeMCU_1
  EEPROM.begin(512);
#endif
  unsigned int nodeid=0;
  //for(unsigned int i=0;i<sizeof(nodeid);i++){nodeid=nodeid<<8;nodeid|=EEPROM.read(_memloc+i);}; // We store our node ID as an unsigned INT using EEPROM bytes 2 and 3
  for(unsigned int i=0;i<2;i++){nodeid=nodeid<<8;nodeid|=EEPROM.read(_memloc+i);}; // We store our node ID as an unsigned INT using EEPROM bytes 2 and 3
  return nodeid;
}

void NodeID::set(unsigned int idToSet) {
  EEPROM.write(_memloc,idToSet>>8);
  EEPROM.write(_memloc+1,idToSet&0xff);
#ifdef ARDUINO_ESP8266_NODEMCU // Wemos_D1_ESP8266_NodeMCU_1  
  EEPROM.commit();
#endif  

}
#endif
