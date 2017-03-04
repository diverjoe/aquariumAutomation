/*
Contributions:
Web Server example

This requires the W5500 ethernet chipset.

 */

#include <SPI.h>
#include <Ethernet2.h>

// Enter a MAC address for your controller below.
// These must be unique per local area network!!
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

// Define PostData pieces
String dataType; // The InfluxDB DB name
String sourceDevice; // The hostname of the arduino
String sensorName; // The sensor name-id sending the data
int sensorData = 0; // The data piece, int - analog pin 2
int potPin = 2; // The data piece, int - analog pin 2
String dataScale; // Relevant scale, not sure how useful this is
String PostData; // Defining the post JSON body

EthernetClient client;

void setup() {
	// Open serial communications and wait for port to open:
	Serial.begin(9600);
  Serial.println("Attempting to configure Ethernet using DHCP...");
  Ethernet.begin(mac);

  delay(1000);
  
	// start the Ethernet connection:
	if (Ethernet.begin(mac) == 0) {
		Serial.println("Failed to configure Ethernet using DHCP!!");
		// no point in carrying on, so do nothing forevermore:
		for (;;)
			;
	}
	// if you get a connection, report back via serial:
  Serial.println("Successfully configured Ethernet using DHCP...");

  
  dataType = "SensorData";
  sourceDevice = "Arduino-2";
  sensorName = "tempProbe-2";
  // sensorData = (int) sensorPackage.readSensor();
  dataScale = "celcius";

  PostData = "";
}

void loop() {
  sensorData = analogRead(potPin);
  PostData = "{ \"dataType\":\"" + dataType + "\",\"sourceDevice\":\"" + sourceDevice + "\",\"sensorName\":\"" + sensorName + "\",\"sensorData\":" + sensorData + ",\"dataScale\":\"" + dataScale + "\" }";
 
  if (client.connect("data.practicaltech.ca", 3000)) {
    // Debug: Serial.println("connected");
    // Make a HTTP request:
    client.println("POST /receiveSensorData HTTP/1.1");
    client.println("Host: data.practicaltech.ca");
    client.println("Connection: close");
    client.println("Content-Type: application/json;charset=utf-8");
	  client.print("Content-Length: ");
	  client.println(PostData.length());
	  client.println();
	  client.print(PostData);
  } 
  else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }

	if (client.connected()) {
    // Debug: Serial.println("disconnecting");
    client.stop();
	}

  delay(15000);
}
