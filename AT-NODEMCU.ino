#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "i-U_zr4aLytVmbBV1EAh7hVNrL7Xfn9R";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "project";
char pass[] = "vishwaja";
WidgetTerminal terminal(V0);
void setup()
{
 terminal.clear();
  
    myservo.attach(D3); 
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  if(digitalRead(D4)||(digitalRead(D7)==0))
  {
  terminal.println("car movement detected");// put your main code here, to run repeatedly:
 //  in steps of 1 degree
  myservo.write(180);              // tell servo to go to position in variable 'pos'
  delay(3000); 
  myservo.write(0); // waits 15ms for the servo to reach the position
  
  }
  
  if(digitalRead(D0)==0)
 {
  terminal.println("slot1 full");
}
  if(digitalRead(D1)==0)
 {
  terminal.println("slot2 full");
 }
  if(digitalRead(D2)==0)
 {
  terminal.println("slot3 full");
 }
 if(digitalRead(D2))
 {
  terminal.println("slot3 empty");
 }
 if(digitalRead(D1))
 {
  terminal.println("slot2 empty");
 }
 if(digitalRead(D0))
 {
  terminal.println("slot1 empty");
 }
 delay(1000);
  Blynk.run();
}
