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

unsigned int NodeID::get()
{
  unsigned int nodeid=EEPROM.read(_memloc)<<8;
  return nodeid|=EEPROM.read(_memloc+1); // We store our node ID as an unsigned INT using EEPROM bytes 2 and 3
}

void NodeID::set(unsigned int idToSet)
{
  EEPROM.write(_memloc,idToSet>>8);
  EEPROM.write(_memloc+1,idToSet&0xff);
}
#endif
