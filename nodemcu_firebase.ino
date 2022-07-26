#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
 
// Set these to run example.
#define FIREBASE_HOST "miles-711c9-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "WkBwMCKkr9YimzxmcqwbhjKHu8lLcLUXrHKsffk8"
#define WIFI_SSID "Rohit" //provide ssid (wifi name)
#define WIFI_PASSWORD "Neeta702" //wifi password
void setup()
{ 
 
 // Debug console
 Serial.begin(9600);
// connect to wifi.
 WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 Serial.print("connecting");
 while (WiFi.status() != WL_CONNECTED)
 {
 Serial.print(".");
 delay(500);
 }
 Serial.println();
 Serial.print("connected: ");
 Serial.println(WiFi.localIP());
 
 Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
if(Firebase.failed())
 {
 Serial.print(Firebase.error());
 }
 else{
 
 Serial.print("Firebase Connected");
 Firebase.setString("Value","0");
 }
}
 
void loop()
{
for(int i = 0; i <= 100; i++)
 { 
  Serial.println(i);
    Firebase.setInt("Value",i);
    delay(1000);
 }
 
}
