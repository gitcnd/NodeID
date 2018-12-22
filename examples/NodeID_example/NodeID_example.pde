/*
  NodeID_example.cpp v1.0 - shows how to set and get an ID using NodeID
  (C) Copyright 2018 (GNU GENERAL PUBLIC LICENSE, Version 3) - Chris Drake <cdrake@cpan.org>
*/

#include <NodeID.h>
#include <SerialID.h>
SerialIDset("\n#\tv2.03 " __FILE__ "\t" __DATE__ " " __TIME__);

NodeID NodeID(2);	// We use the 3rd and 4th bytes (zero-based offset 2 and 3) inside EEPROM to store our ID.  NB: EEPROM has write-cycles limited to 10,000

void setup() {
  SerialIDshow(9600);	// NB: Fast speeds will garble any input you want to send back to the MCU
  unsigned int myNodeID=NodeID.get();

  if((myNodeID==0)||(myNodeID>65534)) {
    Serial.print("Invalid NodeID ("); Serial.print(myNodeID);
    Serial.println(") found.");
    Serial.print("Enter a new NodeID in decimal to set it now: ");
    myNodeID=0;
    unsigned int newNodeID=0;
    while(myNodeID==0) {
      if (Serial.available()) {
	int inByte = Serial.read(); Serial.write(inByte);
	if((inByte>='0')&&(inByte<='9')) newNodeID=newNodeID*10+inByte-'0';
	else myNodeID=newNodeID; // Any non-digit means set now
      }
    }
    NodeID.set(myNodeID);
  }
} // setup

void loop() {
  Serial.print("My NodeID is:");
  Serial.println(NodeID.get());
  delay(2000);
}


