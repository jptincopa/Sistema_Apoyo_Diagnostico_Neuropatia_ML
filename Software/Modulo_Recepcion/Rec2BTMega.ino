String readString;
String data2,data3,data2R,data3R;
String pot1String = "0", pot2String = "0";
float pot1, pot2;

void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);
}

void loop() {
  // read from port 1, send to port 0:
 /* if (Serial2.available()) {
    delay(10);
    int inByte = Serial2.read();
    Serial.write(inByte); 
  }
  Serial.println("  -  ");
  */
  // read from port 0, send to port 1:

if(Serial2.available() > 0)
  {
   data2 = Serial2.readStringUntil('\n'); 
   if(data2.length()==54)
   {
   data2R=data2;
    }
   else{
    data2R="IZQ,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00";
    
    }   
    delay(20);
  }
Serial.print(data2R);
Serial.print(",");


if(Serial3.available() > 0)
  {
   String data3 = Serial3.readStringUntil('\n'); 
   if(data3.length()==54)
   {
   data3R=data3;
    }
    else{
      data3R="DER,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00";
      
    }
   delay(20);
 }

Serial.println(data3R);    
  /*
if(Serial3.available() > 0)
  {
    data3 = Serial3.readStringUntil('\n');  
 Serial.println(data3);
 
  }*/

   /*
  String payload = ""; 
  if (data != "0")
  {
    int offset = data.indexOf("U*"); //This is the header (0x552A)
    if (offset >= 0)
    {
      payload = data.substring(offset + 3, data.indexOf('\n'));
      char value = data.charAt (offset + 2);
      switch (value)
      {
        case 'A':
          pot1String = payload;
          break;
        case 'B':
          pot2String = payload;
          break;
      //Add more case as the project grow
      }
    }
  }
  */
  //convert strings to float
  pot1 = pot1String.toFloat();
  pot2 = pot2String.toFloat();


}
