#include <SoftwareSerial.h>
SoftwareSerial mySerial =  SoftwareSerial(D1, D2);/// rx tx
#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include "SoftwareSerial.h"
#include "FirebaseESP8266.h"  // Install Firebase ESP8266 library
#include <ESP8266WiFi.h>
#define WIFI_SSID "HITEC EVENT"
#define WIFI_PASSWORD "MAD@54321"
#define FIREBASE_HOST "https://solutions-ce892-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "Z7vHIbwsR7CBPg58vDSkRwczW3HrrULggeukBpSR"
FirebaseData firebaseData;
FirebaseData getdata1;
FirebaseJson json;
void setup() {
  Serial.begin(9600);
  Serial.println("st");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  pinMode(D7,INPUT);
  pinMode(D8,INPUT);
  

}
void loop() {

if(digitalRead(D7)==1){   Firebase.setString(firebaseData, "Railway 1","CLosed" );}
if(digitalRead(D7)==0){   Firebase.setString(firebaseData, "Railway 1","Open" );}

 
if(digitalRead(D8)==1){   Firebase.setString(firebaseData, "Railway 2","CLosed" );}
if(digitalRead(D8)==0){   Firebase.setString(firebaseData, "Railway 2","Open" );}
  
    

}
