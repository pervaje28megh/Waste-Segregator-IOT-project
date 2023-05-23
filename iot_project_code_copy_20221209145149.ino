#include<Servo.h>
Servo s1;
int Moisture_dig_signal=A0;
int Sensor_State=1;
void setup() {
s1.attach(9);
pinMode(2,INPUT);
 pinMode(Moisture_dig_signal,INPUT);
 Serial.begin(9600); // put your setup code here, to run once:

}
void dry()
    {
      s1.write(45);
    }

    void wet()
    {
      s1.write(135);
    }

    void neutral()
    {
      s1.write(90);
    }

void loop() {
  int touch=digitalRead(2);
 Serial.print("analog level:");
 Sensor_State=analogRead(Moisture_dig_signal);
 
 if(Sensor_State>850 && touch==1) {
   Serial.println("dry");
   dry();
   delay(1000);

   }
   else if(Sensor_State<=850 && touch==1) {
     Serial.println("wet");
     wet();
     delay(1000);
   }
    else {
      neutral();
    }
     
     delay(200);// put your main code here, to run repeatedly:

}