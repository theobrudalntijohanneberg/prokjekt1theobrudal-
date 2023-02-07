#include "U8glib.h"
U8GLIB_SSD1306_128X64 oled(U8G_I2C_OPT_NONE);
const int button1Pin = 2; 
const int button2Pin = 3; 
const int greenlamppin = 9;
const int redlamppin = 8;
int runningcount = 0;
int button1State = 0;
int button2State = 0;
  void setup() {
   pinMode(button1Pin, INPUT);
   pinMode(button2Pin, INPUT);
   pinMode (greenlamppin, OUTPUT);
   Serial.begin(9600);
  
}

void loop() {
   button1State = digitalRead(button1Pin);
   button2State = digitalRead(button2Pin);
   if (button1State == HIGH) {
    // turn LED on:
   runningcount = runningcount + 1;
    Serial.println("+");
    delay(250);
   }if(button2State == HIGH) {
    // turn LED off:
    runningcount = runningcount - 1;
    Serial.println("-");
    delay(250);}
    if (runningcount >0){
      digitalWrite (greenlamppin,HIGH);
      digitalWrite (8,LOW);
      Serial.println("green");}
    else {
      digitalWrite (8,HIGH);
      digitalWrite (greenlamppin,LOW);}
  draw();
}
void updatecount(){

  
  }


void draw() {

  // Set font to Helvetica size 10
  oled.setFont(u8g_font_helvB10);
  oled.firstPage();
  do {
    oled.drawStr(20, 33, String(runningcount).c_str());
  } while (oled.nextPage());
  
}
