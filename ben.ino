// code update 21/04/2546
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6TB9L1Fi5"
#define BLYNK_TEMPLATE_NAME "Benjawan"
#define BLYNK_AUTH_TOKEN "IFDv8KWafKI3gCDNGV364DLqUPC3wyq-"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"
//#include <TridentTD_LineNotify.h>

char ssid[] = "Queenieris";
char pass[] = "Benjawanben";

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
#define DHTPIN 4     // Digital pin connected to the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

const int relay = 13;

void setup()
{
  // Debug console
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(relay,OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println(F("Succesfully Connected!"));
  dht.begin();
  // LINE.setToken(LINE_TOKEN);
  // timer.setInterval(1000000, Sensor);
}

BLYNK_WRITE(V0) {   
  int value = param.asInt();
  Serial.println(value);
    if(value == 1){
     digitalWrite(relay,0);
     digitalWrite(LED_BUILTIN,HIGH);
    }else{
      digitalWrite(relay,1);
      digitalWrite(LED_BUILTIN,LOW);
    }
  }
void loop()
{
  Blynk.run();
  timer.run(); 
}

// void Sensor()
// {
//   float h = dht.readHumidity();
//   float t = dht.readTemperature();
//   if (isnan(h) || isnan(t)) {
//     Serial.println("Failed to read from DHT sensor!");
//     delay(5000);
//     return;
//   }
//   Serial.print("Humidity is: "); 
//   Serial.println(h, 1);
//   Serial.print("Temperature is: "); 
//   Serial.println(t, 1);
  
//   Blynk.virtualWrite(V2, h);
//   Blynk.virtualWrite(V3, t);
//   LINE.notify("Humidity is: "+String(h)+" %"); 
//   LINE.notify("Temperature is: "+String(t)+" C"); 
// }
