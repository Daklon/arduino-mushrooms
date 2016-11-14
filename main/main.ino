#include <Wire.h>
#include <LiquidCrystal_I2C.h>


// initialize the library
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
            
uint8_t bell[8]  = {0x3,0x4,0x8,0x1f,0x8,0x1f,0x4,0x3};

byte temp[8] = {
  0b00100,
  0b01010,
  0b01010,
  0b01110,
  0b01110,
  0b11111,
  0b11111,
  0b01110
};

byte hum[8] = {
  0b00100,
  0b00100,
  0b01010,
  0b01010,
  0b10001,
  0b10001,
  0b10001,
  0b01110
};

byte grad[8] = {
  0b01110,
  0b01010,
  0b01110,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte percent[8] = {
  B11000,
  B11001,
  B00010,
  B00100,
  B01000,
  B10011,
  B00011,
  B00000
};
void setup()
{
  // set up number of columns and rows
  lcd.begin(20, 4);

  // create a new custom character
  lcd.createChar(0, temp);
  lcd.createChar(1, hum);
  lcd.createChar(2, grad);
  lcd.createChar(3, percent);
  lcd.createChar(4, bell);

  // print the custom char to the lcd
  // why typecast? see: http://arduino.cc/forum/index.php?topic=74666.0
  lcd.home ();
  lcd.setCursor (0,0);
  lcd.write((uint8_t)0);
  lcd.setCursor (1,1);
  lcd.write((uint8_t)1);
  lcd.setCursor (0,2);
  lcd.write((uint8_t)2);
  lcd.setCursor (1,3);
  lcd.write(byte(3));
  lcd.setCursor (4,3);
  lcd.print((char)4);
  lcd.print("test");
}

void loop()
{
  
}
            
