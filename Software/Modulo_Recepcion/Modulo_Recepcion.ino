#include <Wire.h>
#include <Adafruit_ADS1015.h>
#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  
SoftwareSerial BT(10,11);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth

Adafruit_ADS1115 ads;
const float multiplier = 0.0001875F;

void setup()
{
  BT.begin(9600);       // Inicializamos el puerto serie BT (Para Modo AT 2)
  Serial.begin(9600);   // Inicializamos  el puerto serie  
  ads.begin();
}
 
void loop()
{ int16_t adc0, adc1, adc2, adc3;
  adc0 = ads.readADC_SingleEnded(0);
  adc1 = ads.readADC_SingleEnded(1);
  adc2 = ads.readADC_SingleEnded(2);
  adc3 = ads.readADC_SingleEnded(3);
  float F7=adc0 * multiplier;
  float F8=adc1 * multiplier;
  float F9=adc2 * multiplier;
  float F10=adc3 * multiplier;
  
  
  float v1=analogRead(A0);
  float F1=ToVolt(v1);
  float v2=analogRead(A1);
  float F2=ToVolt(v2);
  float v3=analogRead(A2);
  float F3=ToVolt(v3);
  float v4=analogRead(A3);
  float F4=ToVolt(v4);
  float v5=analogRead(A6);
  float F5=ToVolt(v5);
  float v6=analogRead(A7);
  float F6=ToVolt(v6);
  
 char DATOS[200]="IZQ,";
 char buff[10];
 dtostrf(F1,4,2,buff);
 strcat(DATOS,buff); 
 strcat(DATOS,",");
 dtostrf(F2,4,2,buff);
 strcat(DATOS,buff); 
 strcat(DATOS,","); 
 dtostrf(F3,4,2,buff);
 strcat(DATOS,buff); 
 strcat(DATOS,","); 
 dtostrf(F4,4,2,buff);
 strcat(DATOS,buff); 
 strcat(DATOS,","); 
 dtostrf(F5,4,2,buff);
 strcat(DATOS,buff); 
 strcat(DATOS,","); 
 dtostrf(F6,4,2,buff);
 strcat(DATOS,buff); 
    strcat(DATOS,","); 
    dtostrf(F7,4,2,buff);
    strcat(DATOS,buff); 
    strcat(DATOS,","); 
    dtostrf(F8,4,2,buff);
    strcat(DATOS,buff); 
    strcat(DATOS,","); 
    dtostrf(F9,4,2,buff);
    strcat(DATOS,buff); 
    strcat(DATOS,","); 
    dtostrf(F10,4,2,buff);
    strcat(DATOS,buff); 
// strcat(DATOS,","); 

 // sprintf("F1=%s,F2=%s",F1,F2);
Serial.println(DATOS);
BT.println(DATOS);
delay(10);

}

float ToVolt(float a)
{
  return (a/1024)*5;
}
