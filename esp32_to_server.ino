#include <WiFi.h>
#include <SPI.h>

//Pin at which sensor is sending moisture data through
#define INPUT_PIN 36

//WIFI username(ssid) and password
const char* ssid     = "";
const char* password = "";

//values recieved from moistureData
float moistureData;
IPAddress server(192,168,1,90); 
WiFiClient client;

/* Setup for Ethernet and RFID */

void setup() {
  //Write to console 9600
  Serial.begin(9600);

  Serial.print("Connecting to ");
  Serial.println(ssid);

  //Connect to WiFi network
  WiFi.begin(ssid, password);

  //Loops stops the code until microcontroller is connected to WiFi network
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
      }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  delay(1000);
}
//------------------------------------------------------------------------------


void loop(){
  //moisture data recieved from moisture sensor
  moistureData = (analogRead(INPUT_PIN));
  Sending_To_phpmyadmindatabase(); 
  delay(3000); // interval
}


/**
     * Makes an HTTP request to a server such that moisture data is added to a table from a database on a WAMP server
     * This is accomplished with a php code
     *
     */
 void Sending_To_phpmyadmindatabase()   //CONNECTING WITH MYSQL
 {
   if (client.connect(server, 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    Serial.print("GET /moistureTest/testing.php?moisture=");
    client.print("GET /moistureTest/testing.php?moisture=");    
    Serial.println(moistureData);
    client.print(moistureData);
    client.print(" ");  
    client.print("HTTP/1.1\r\n");
    //client.println("Host: \r\n");
    client.println("Host: gz.qrimp.net\r\n");
    client.println("Connection: close\r\n\r\n");

  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
}
