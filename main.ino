#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;


const char* ssid = "";   // Your Network SSID
const char* password = "";       // Your Network Password
float val;
float pin = A0;
WiFiClient client;

unsigned long myChannelNumber = 1712248; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "SR92766NDKZSZCL3"; //Your Write API Key

void setup()
{
  Serial.begin(115200);
  delay(10);
  // Connect to WiFi network
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
}

void loop()
{

  val = (300-analogRead(pin))/(10);
  //val = (analogRead(pin)*0.322265*10);
  Serial.print("Temperature:");
  Serial.print(val);
  Serial.println("*C");
  
  delay(1000);
  ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak
  delay(100);
}
