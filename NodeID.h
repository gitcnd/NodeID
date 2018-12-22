/*
  NodeID.h v1.0 - Get (and initially set) a unique serial-number identity from EEPROM for each of your MCU boards (so the same code running on many different boards knows how to differentiate itself from the others)
  (C) Copyright 2018 (GNU GENERAL PUBLIC LICENSE, Version 3) - Chris Drake <cdrake@cpan.org>
*/

#ifndef NodeID_h
#define NodeID_h

#include "Arduino.h"
#include <EEPROM.h>     // for saving settings (SD card data file name) etc.

class NodeID
{
  public:
    NodeID(unsigned int);
    unsigned int get();
    void set(unsigned int);
  private:
    int _memloc;
};

#endif

