
#include <Key.h>
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define KS_Isi 4

int LED=13;

char Data[KS_Isi];
char Master[KS_Isi]="055";
byte data_count=0, master_count=0;
bool Katasandi_oke;
char customKey;

const byte ROWS=4;
const byte COLS=4;

char hexaKeys[ROWS][COLS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  lcd.begin();
  lcd.backlight();
  pinMode(13,OUTPUT);

}

//line is added by zky
void loop() {
  lcd.setCursor(0,0);
  lcd.print("18518241055");
  lcd.setCursor(0,1);
  customKey = customKeypad.getKey();
  if(customKey){
    Data[data_count]=customKey;
    lcd.setCursor(data_count+0,1);
    lcd.print(Data[data_count]);
    data_count+1;
  }

if(data_count == KS_Isi-1){
  lcd.clear();
  digitalWrite(13,LOW);
  if(!strcmp(Data, Master)){
    lcd.print(Data);
    digitalWrite(13,HIGH);
    delay(3000);
    digitalWrite(13,LOW);  
    }
    
  else{
    lcd.print(Data);
    digitalWrite(13,LOW); 
    delay(1000);
  }

  // this line is added by zky
  lcd.clear(); 
  clearData();
}

}

void clearData(){
  while(data_count!=0){
    Data[data_count--]=0;
  }
  
  return;
}
