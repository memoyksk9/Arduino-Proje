#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); // Bu kodu kullanırken ekranda yazı çıkmaz ise 0x27 yerine 0x3f yazınız !!
#define led1 3 
#define led2 5
#define led3 6
const int sensorPin = A0;

void setup() {
pinMode (led1, OUTPUT); 
pinMode (led2, OUTPUT); 
pinMode (led3, OUTPUT); 
Serial.begin(9600);
 lcd.begin();
for (int i=0 ; i<5 ;i++)
{lcd.setCursor(0,0); // İlk satırın başlangıç noktası
 lcd.print("21720690036");
 lcd.setCursor(0,1); // İkinci satırın başlangıç noktası
 lcd.print("MEHMETYUKSEK");
 delay(500);
  lcd.clear();
  delay(500);}
  pinMode(sensorPin, INPUT);
}
void loop(){
int lightValue = analogRead(sensorPin);
 lcd.setCursor(0, 0);
  lcd.print("IsIk siddeti:");

  lcd.setCursor(0, 1);
  lcd.print(lightValue);

  delay(1000);
int isik=analogRead(A0);
Serial.println(isik);
delay(200);
if (isik<250){
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
}
else{
  digitalWrite(led1,LOW);
} 

  
    if (isik>250 && isik<=400){
  digitalWrite(led2,HIGH);
  digitalWrite(led3,LOW);
  digitalWrite(led1,LOW);
}
else{
  digitalWrite(led2,LOW);   
}

  if (isik>400){
  digitalWrite(led3,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led1,LOW);
}
else{
  digitalWrite(led3,LOW);
}
}
