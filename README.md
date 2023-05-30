# esp-now-control-xmit

The purpose of the control xmit sketch is adjusting the colour and brightness of the RGB LED built onto a remote EXP-32 board.  

* The transmitting ESP32 is connected to a computer running a terminal program such as PuTTY or CoolTerm. 
* A single letter typed into the terminal window acts as a command for the remote ESP32.
* In this example the MAC address of the remote ESP32 is coded into esp-now-control-xmit.ino
* The two boards communicate via WiFi modules built into ESP32 the boards.

In exploring the use of ESP NOW on a ESP32-S2-DEVKITC-1 board I found a simple example at 

* [https://dronebotworkshop.com/esp-now/#One-Way_Initiator_Sketch](https://dronebotworkshop.com/esp-now/#One-Way_Initiator_Sketch)

All the sketches on that page can be downloaded in a zip file if you go to the bottom of the page. The entire page contains useful 
information that I will not duplicate here.

I took the initiator sketch and modified it to control the RGB LED on a second ESP32. My modified control receiver can be found at 
[https://github.com/danpeirce/esp-now-command-rcv](https://github.com/danpeirce/esp-now-command-rcv)

... more to follow...