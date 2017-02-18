/*
Contributions:
Web Server example

This requires the W5500 ethernet chipset.

 */

#include <SPI.h>
#include <Ethernet2.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
// char targetServer[] = "data.practicaltech.ca";
byte server[] = { 192, 168, 1, 140 };
EthernetClient client;

String PostData;

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

  PostData = "";
}

void loop() {
  PostData = "{ \"dataType\":\"SensorData\",\"sourceDevice\":\"Arduino-1\",\"sensorName\":\"tempProbe-1\",\"sensorData\":22,\"dataScale\":\"celcius\" }";
  
  if (client.connect(server, 3000)) {
    Serial.println("connected");
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
    Serial.println("disconnecting");
    client.stop();
	}

  delay(15000);
}
