/*
 This program demonstrates the dGPS library from Dexter Industries for Arduino
 
 For use with the Dexter Industries GPS Shield.  The dGPS can be found here:
   - http://dexterindustries.com/Arduino-GPS_Shield.html
 
 This code was originally based on the work of others.  You can see the original work here:
   - SoftwareSerial Library:  http://www.arduino.cc/en/Reference/SoftwareSerial
   - GPS Tutorial:  http://www.arduino.cc/playground/Tutorials/GPS
 
 See our Arduino GPS Converting Coordinates for information on converting coordinates
 from GPS Style Coordinates (ddmm.ssss) to Decimal Style Coordinates (dd.mmssss).
 
 How it works:
   - The dGPS requires the SoftwareSerial.h library.
   - The GPS is initialized in the setup function.
   - The GPS is updated: values for location, time, etc, are updated using the ".update" function.
   - The values are read using their respective calls.  These values stay the same until "update" is called again. 
   
 Simplified by Jeff Conrad to just show the specific current measurements, no destination.

*/

#include "string.h"
#include "ctype.h"
#include "SoftwareSerial.h"
#include "dGPS.h"

// Software serial TX & RX Pins for the GPS module
// Initiate the software serial connection

int ledPin = 13;                  // LED test pin
dGPS dgps = dGPS();               // Construct dGPS class

void setup() {
  pinMode(ledPin, OUTPUT);       // Initialize LED pin
  Serial.end();                  // Close any previously established connections
  Serial.begin(9600);            // Serial output back to computer.  On.
  dgps.init();                   // Run initialization routine for dGPS.
  delay(1000);                   // Delay 1 sec between pings
}

void loop() {
  dgps.update(0,0);

  Serial.print("UTC Date(DDMMYY): ");
  Serial.println(dgps.Date());    // UTC date.  Date is in format:  DDMMYY (D - Day; M - Month; Y-Year)

  Serial.print("UTC Time: ");
  Serial.println(dgps.Time());    // .Time returns the UTC time (GMT) in HHMMSS, 24 huor format (H-Hour; M-Minute; S-Second)
  
  Serial.print("Status: ");
  Serial.println(dgps.Status());  // A - Satellites acquired and a valid signal.  V - No sats and not a valid signal.
  
  Serial.print("Latitude: ");
  Serial.print(dgps.Lat(), 6);    // Latitude - in DD.MMSSSS format (decimal-degrees format)  (D-Degree; M-Minute; S-Second)
  Serial.println(" degrees");
  
  Serial.print("Longitude: ");
  Serial.print(dgps.Lon(), 6);    // Longitude - in DD.MMSSSS format (decimal-degrees format)  (D-Degree; M-Minute; S-Second)
  Serial.println(" degrees");
  
  Serial.print("Velocity: ");
  Serial.print(dgps.Vel(), 6);    // Velocity, in knots.
  Serial.println(" knots");
  
  Serial.print("Heading: ");
  Serial.print(dgps.Head(), 6);   // Heading, in degrees
  Serial.println(" degrees");
  
  Serial.println("");
}
