# ArduinoApollo11

The goal of this project is to take the recently released Apollo 11 code and port portions of it to run on a modern Arduino microcontroller in an effort to (hopefully) bring back a mostly dead language. This controller will ultimately go into a 1:70 scale Saturn V model rocket and send back telemetry data.

The sensors on the rocket will include:
  * Accelerometer
  * Altimeter
  * Gyrometer
  * GPS
  * Nose cone separation detection
  
The nose cone separation sensor would detect the deployment of the parachute and if it detects a failure possibly set off a secondary parachute.

The GPS would be used primarily for recovery, transmitting GPS coordinates during the entire launch.

Ground communications will use an FM transmitter in the rocket and a USB FM receiver on the ground, hopefully this will be strong enough and have adequate bandwidth to transmit the telemetry data.

It would be nice to have an emulated DSKY on the ground to enter commands in to load the program code, perhaps even start the ignition of the rocket.

