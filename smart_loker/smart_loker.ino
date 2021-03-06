#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "FirebaseESP8266.h"
#include <Wire.h>

//define the wifi credentials
#define WIFI_SSID "Sassung"
#define WIFI_PASSWORD "luwakwhitekopi"

//define firebase project host name
#define FIREBASE_HOST "https://smart-locker-f9a91-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "saVXFFuIr7sPGn2amjTo7cel8jqs4BdqYPKVr1b4"

// LCD
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd1 (0x26, 16, 2); // lcd loker 1
LiquidCrystal_I2C lcd2 (0x27, 16, 2); // lcd loker 2

// pin sensor
int prs1 = 13; //
int prs2 = 3;
int rs1, rs2;

// pin solenoit
int sol1 = 12;
int sol2 = 14;

int state1, state2, state3;
//define firebase data object
//FirebaseData fbdo;
FirebaseData firebaseData;

//define the firebaseauth for authentication data
//FirebaseAuth auth;
//FirebaseJson json;

int i,a,b = 0;

byte interval = 1000;
unsigned long  prev, prev2 = 0;

void setup() {
Serial.begin(115200);
lcd1.begin();
lcd2.begin();
lcd1.backlight();
lcd2.backlight();

WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("Connecting to Wi-Fi");
lcd1.setCursor(0,0);
lcd1.print("Connect to Wi-Fi");
lcd2.setCursor(0,0);
lcd2.print("Connect to Wi-Fi");
while (WiFi.status() != WL_CONNECTED)
{
  Serial.print(".");
  
    lcd1.setCursor(i,1);
    lcd2.setCursor(i,1);
    lcd1.print(".");
    lcd2.print(".");
    
  i++;
  delay(300);

}
Serial.println();
Serial.print("Connected with IP; ");
Serial.println(WiFi.localIP());
Serial.println();

Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
Firebase.reconnectWiFi(true);

pinMode (prs1, INPUT_PULLUP);
pinMode (prs2, INPUT_PULLUP);
pinMode (sol1, OUTPUT);
pinMode (sol2, OUTPUT);
digitalWrite(sol1, HIGH);
digitalWrite(sol2, HIGH);

pinMode(LED_BUILTIN, OUTPUT);

lcd1.clear();
lcd2.clear();
}

void loop() {
  // put your main code here, to run repeatedly:

if (WiFi.status() != WL_CONNECTED)
{
  lcd1.clear();
  lcd2.clear();
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  lcd1.setCursor(0,0);
  lcd1.print("Connect to Wi-Fi");
  lcd2.setCursor(0,0);
  lcd2.print("Connect to Wi-Fi");  

while (WiFi.status() != WL_CONNECTED){


      Serial.print(".");
  
    lcd1.setCursor(i,1);
    lcd2.setCursor(i,1);
    lcd1.print(".");
    lcd2.print(".");
    
  i++;
  delay(300);
}
  lcd1.clear();
  lcd2.clear();
}

lcd1.setCursor(0,0);
lcd1.print("    LOKER 1    ");
lcd1.setCursor(0,1);
lcd1.print ("Status : ");

lcd2.setCursor(0,0);
lcd2.print("    LOKER 2    ");
lcd2.setCursor(0,1);
lcd2.print ("Status : ");

if(Firebase.getString(firebaseData, "/Locker/1/Status"))
  {
    //Success
    //Serial.print("Get int data success, String = ");
    lcd1.setCursor(9,1);
    lcd1.print (firebaseData.stringData());
    }else{
    //Failed?, get the error reason from firebaseData

    Serial.print("Error in getInt, ");
    Serial.println(firebaseData.errorReason());
  }

  if(Firebase.getString(firebaseData, "/Locker/2/Status"))
  {
    //Success
    //Serial.print("Get int data success, String = ");
    lcd2.setCursor(9,1);
    lcd2.print (firebaseData.stringData());
    }else{
    //Failed?, get the error reason from firebaseData

    Serial.print("Error in getInt, ");
    Serial.println(firebaseData.errorReason());
  }

rs1 = digitalRead(prs1);
rs2 = digitalRead(prs2);

//state3 = 0;

locker_1();
locker_2();
alarm();
lock_again();

delay(10);
}
