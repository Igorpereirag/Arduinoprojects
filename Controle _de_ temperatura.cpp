#include <LiquidCrystal.h>
#define motor 10
#define tmp A5
LiquidCrystal lcd(9,8,4,5,6,7);

void setup ()
{ 
  lcd.begin(16,2);
  Serial.begin(9600);

}
  
void loop()
{
 
  // Obtenha uma leitura do sensor de temperatura:
  int reading = analogRead(tmp);
  // Converta a leitura em voltagem:
  float voltage = reading * (5000 / 1024.0);
  // Converta a tensão na temperatura em Celsius:
  float temperature = (voltage - 500) / 10;
    // Imprima a temperatura no Monitor lcd:
  lcd.setCursor(0, 0);
  lcd.print("Temperatura:");
  lcd.setCursor(0, 1);
  lcd.print(temperature);
  lcd.write(B10110010); // imprime o caractere personalizado
  lcd.print("C");
  delay(1000); // espere um segundo entre as leituras
  
  if (temperature>25){//se for maio de 25 graus, ativa a mensagem e o motor
   analogWrite(motor,400);
    delay(1000);
    lcd.clear();
    lcd.print("motor ligado");
    delay(1000);
  }
  
  if (temperature>28){//se for maio de 28 graus, ativa a mensagem e o motor
   analogWrite(motor,1000);
    delay(4000);
    lcd.clear();
    lcd.print("motor ligado");
    delay(1000);
  
  }
  if(temperature<25){// se for meno exibe a temperatura normal
     analogWrite(motor,0);
    lcd.clear();
    lcd.setCursor(0, 0);
  lcd.print("Temperatura:");
  lcd.setCursor(0, 1);
  lcd.print(temperature);
  lcd.write(B10110010); // imprime o caractere personalizado
  lcd.print("C motorOff");
  delay(1000); // espere um segundo entre as leituras

}
  }
