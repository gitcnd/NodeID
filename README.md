# NodeID
Get (and initially set) a unique serial-number identity from EEPROM for each of your MCU boards (so the same code running on many different boards knows how to differentiate itself from the others)

NB: The word "Node" is not related to the (stupidly named) "NodeMCU" boards - this lib is used when you have many Nodes in a network, and they need to ident each other.


# SYNOPSIS

```C
  #include <NodeID.h>
  NodeID NodeID(2);	// Set which EEPROM bytes to use (bytes 2 and 3 in this example)

  void setup() {                
    unsigned int myNodeID=NodeID.get();	// get it (see the NodeID_example in this package to set the ID too)
  }
```

# FUNCTIONS

```C
  get();	// retrieve the ID
  set(42);	// Set the unsigned int NodeID to the number 42
```


# HOW TO INSTALL

(Method 1)

1. Open a terminal (commandline, bash shell, whatever)
2. Change into your Arduino folder
```bash
   cd /Applications/Arduino.app/Contents/Java/libraries/
   (or)
   cd ~/Arduino/libraries/
```
3. grab and install this code
```bash
   git clone https://github.com/gitcnd/NodeID.git
```
4. restart your arduino IDE
5. Choose File => Examples => NodeID => NodeID_example
6. Hit the "build" button an enjoy!

(Method 2) - see https://www.arduino.cc/en/Guide/Libraries

1. Download the ZIP of this repo: https://github.com/gitcnd/NodeID/archive/master.zip
2. In your IDE, select Sketch -> Include Library -> Add .ZIP Library
3. Choose File => Examples => NodeID => hello
4. Hit the "build" button an enjoy!
