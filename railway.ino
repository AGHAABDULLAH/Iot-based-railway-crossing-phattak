
#include <LCD_I2C.h>
LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according
#include <Servo.h>

Servo m1;  
Servo m2;  

Servo m3;  
Servo m4;  

void setup() {
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);

  digitalWrite(11,0);
  digitalWrite(12,0);
  
  pinMode(13,OUTPUT);
  digitalWrite(13,1);delay(1000);
  digitalWrite(13,0);delay(1000);
  
 pinMode(6,INPUT);
 pinMode(7,INPUT);
 pinMode(4,INPUT);
 pinMode(5,INPUT);

 Serial.begin(9600);
 Serial.println("St");
 delay(1000);
 lcd.begin(); // If you are using more I2C devices using the Wire library use lcd.begin(false)
 lcd.backlight();
  lcd.setCursor(0, 0);lcd.print("ABC");
  m1.attach(2);  // attaches the servo on pin 9 to the servo object
  m2.attach(3);  // attaches the servo on pin 9 to the servo object

  m3.attach(8);  // attaches the servo on pin 9 to the servo object
  m4.attach(9);  // attaches the servo on pin 9 to the servo object

    m1.write(90);//    open         
    m2.write(90);//
    
   //m1.write(0);m2.write(180);    //          

     m3.write(90);//    open         
     m4.write(90);//

   //m3.write(0);    //      close   
   //m4.write(180); 
}
 int s1;
 int s2;
 int s3;
 int s4;

void loop() {
 read_sensor();
if(s2==0)
{
  digitalWrite(11,1);digitalWrite(12,0);
lcd.setCursor(0, 0);lcd.print("Phatak NO :2");
for(int a=5;a>0;a--){lcd.setCursor(0, 1);lcd.print("Closing :");lcd.print(a);lcd.print("Sec  ");beep();};
lcd.setCursor(0, 1);lcd.print("  Closed    ");
for(int a=90;a>0;a--){m3.write(a);m4.write(180-a);delay(10);}delay(1000);read_sensor();
while(s1==1){read_sensor();Serial.println("1");}
Serial.println("2");
for(int a=5;a>0;a--){lcd.setCursor(0, 1);lcd.print("Opening :");lcd.print(a);lcd.print("Sec  ");beep();};
for(int a=0;a<90;a++){Serial.println("3");m3.write(a);m4.write(180-a);delay(10);}delay(1000);read_sensor();
  digitalWrite(11,0);digitalWrite(12,0);

}

if(s1==0)
{ 
  digitalWrite(11,1);digitalWrite(12,0);
lcd.setCursor(0, 0);lcd.print("Phatak NO :2");
for(int a=5;a>0;a--){lcd.setCursor(0, 1);lcd.print("Closing :");lcd.print(a);lcd.print("Sec  ");beep();};
lcd.setCursor(0, 1);lcd.print("  Closed    ");
for(int a=90;a>0;a--){m3.write(a);m4.write(180-a);delay(10);}delay(1000);read_sensor();
while(s2==1){read_sensor();Serial.println("1");}
Serial.println("2");
for(int a=5;a>0;a--){lcd.setCursor(0, 1);lcd.print("Opening :");lcd.print(a);lcd.print("Sec  ");beep();};
for(int a=0;a<90;a++){Serial.println("3");m3.write(a);m4.write(180-a);delay(10);}delay(1000);read_sensor();
  digitalWrite(11,0);digitalWrite(12,0);

}




if(s3==0)
{  digitalWrite(11,0);digitalWrite(12,1);

lcd.setCursor(0, 0);lcd.print("Phatak NO :1");
for(int a=5;a>0;a--){lcd.setCursor(0, 1);lcd.print("Closing :");lcd.print(a);lcd.print("Sec  ");beep();};
lcd.setCursor(0, 1);lcd.print("  Closed    ");
for(int a=90;a>0;a--){m1.write(a);m2.write(180-a);delay(10);}delay(1000);read_sensor();
while(s4==1){read_sensor();Serial.println("1");}
Serial.println("2");
for(int a=5;a>0;a--){lcd.setCursor(0, 1);lcd.print("Opening :");lcd.print(a);lcd.print("Sec  ");beep();};
for(int a=0;a<90;a++){Serial.println("3");m1.write(a);m2.write(180-a);delay(10);}delay(1000);read_sensor();
  digitalWrite(11,0);digitalWrite(12,0);

}


if(s4==0)
{
    digitalWrite(11,0);digitalWrite(12,1);

lcd.setCursor(0, 0);lcd.print("Phatak NO :1");
for(int a=5;a>0;a--){lcd.setCursor(0, 1);lcd.print("Closing :");lcd.print(a);lcd.print("Sec  ");beep();};
lcd.setCursor(0, 1);lcd.print("  Closed    ");
for(int a=90;a>0;a--){m1.write(a);m2.write(180-a);delay(10);}delay(1000);read_sensor();
while(s3==1){read_sensor();Serial.println("1");}
Serial.println("2");
for(int a=5;a>0;a--){lcd.setCursor(0, 1);lcd.print("Opening :");lcd.print(a);lcd.print("Sec  ");beep();};
for(int a=0;a<90;a++){Serial.println("3");m1.write(a);m2.write(180-a);delay(10);}delay(1000);read_sensor();
  digitalWrite(11,0);digitalWrite(12,0);

}


lcd.setCursor(0, 0);lcd.print("IOT Based ... ");
lcd.setCursor(0, 1);lcd.print("RailWay Phatak ");


}

void read_sensor(void)
{
  s1=digitalRead(6);
  s2=digitalRead(7);
  s4=digitalRead(4);
  s3=digitalRead(5);
  
  Serial.print(" S1:");Serial.print(s1);
  Serial.print(" S2:");Serial.print(s2);
  Serial.print(" S3:");Serial.print(s3);
  Serial.print(" S4:");Serial.println(s4);
  
  }
  void beep(void)
  {
    digitalWrite(13,1);
    delay(400);
    
    digitalWrite(13,0);
    delay(400);
    }
