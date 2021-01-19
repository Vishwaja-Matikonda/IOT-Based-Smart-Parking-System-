#include<LiquidCrystal.h>
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
LiquidCrystal lcd(2,3,4,5,6,7);
void setup() {
    myservo.attach(9);  // attaches the servo on pin 9 to the servo object

for(int i=8;i<13;i++)
{
  pinMode(i,INPUT);// put your setup code here, to run once:
}
lcd.begin(16,2);
lcd.print("paking slot");
  myservo.write(0); // waits 15ms for the servo to reach the position
   Serial.begin(9600);
}

void loop() {
  
      Serial.println(digitalRead(8));
      Serial.println(digitalRead(10));
      Serial.println(digitalRead(11));
      Serial.println(digitalRead(12));
  
 // if(digitalRead(10))
  //{ lcd.clear();
 
    //lcd.print("car detected");// put your main code here, to run repeatedly:
    // in steps of 1 degree
    //myservo.write(180);              // tell servo to go to position in variable 'pos'
    //delay(1500); 
    //myservo.write(0); // waits 15ms for the servo to reach the position
  
  //}
  while((digitalRead(8)==0)&&(digitalRead(11)==0)&&(digitalRead(12)==0)&&(digitalRead(10)))
  { lcd.clear();
 
    lcd.print("slots full");// put your main code here, to run repeatedly:
  while((digitalRead(8)==0)&&(digitalRead(11)==0)&&(digitalRead(12)==0)&&(digitalRead(10)));
  
  }
  if(digitalRead(10))//entrance detected
  { lcd.clear();
 
  lcd.print("car detected");// put your main code here, to run repeatedly:
 //  in steps of 1 degree
  myservo.write(180);              // tell servo to go to position in variable 'pos'
  delay(3000); 
  myservo.write(0); // waits 15ms for the servo to reach the position
  
  }
  
 if(digitalRead(8)==0)
  { lcd.setCursor(0,1);
  lcd.print("S1:F");
 }
  
 else 
  { lcd.setCursor(0,1);
  lcd.print("S1:A");
 
  }
 
 if(digitalRead(11)==0)
  { lcd.setCursor(5,1);
  lcd.print("S2:F");
 }
  
 else //if(digitalRead(11))
  { lcd.setCursor(5,1);
  lcd.print("S2:A");
 
  }
 //else 
 if(digitalRead(12)==0)
  { lcd.setCursor(10,1);
  lcd.print("S3:F");
 }
 else// if(digitalRead(12))
  { lcd.setCursor(10,1);
  lcd.print("S3:A");
 }
 
delay(1000);
}
