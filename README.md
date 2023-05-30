# esp-now-control-xmit

The purpose of the control xmit sketch is adjusting the color and brightness of the RGB LED built onto a remote EXP-32 board. 

In exploring the use of ESP NOW on a ESP32-S2-DEVKITC-1 board I found a simple example at 

* [https://dronebotworkshop.com/esp-now/#One-Way_Initiator_Sketch](https://dronebotworkshop.com/esp-now/#One-Way_Initiator_Sketch)

All the sketches on that page can be downloaded in a zip file if you go to the bottom of the page. The entire page contains useful 
information that I will not duplicate here.

I took the initiator sketch and modified it to control the RGB LED on a second ESP32. My modified control receiver can be found at 
[https://github.com/danpeirce/esp-now-command-rcv](https://github.com/danpeirce/esp-now-command-rcv)

... more to follow...