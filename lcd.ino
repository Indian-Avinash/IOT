
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 

char text[]="www.microcontroller-project.com";
void setup() {
  // set up the LCD's number of columns and rows: 
    lcd.init();// initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
}

void loop() {
  unsigned int i=0;
  // set the cursor to (0,0):
  lcd.setCursor(0, 0);
  
  while(text[i]!='\0'){
   lcd.print(text[i]);
   
   if(i>=14)
  {
          lcd.command(0x18); //Scrolling text to Right
        }
   delay(55);
   i++;
   } 
  // clear screen for the next loop:
  lcd.clear();
  delay(1000);
  
}
