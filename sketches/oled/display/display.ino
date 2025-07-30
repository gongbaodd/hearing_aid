#include <Wire.h>
#include "HT_SSD1306Wire.h"
#include "image.h"

static SSD1306Wire  display(0x3c, 500000, SDA_OLED, SCL_OLED, GEOMETRY_128_64, RST_OLED); 

void displayText(String text) {
    display.clear();
    
    display.setFont(ArialMT_Plain_10);
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    int x = display.width()/2;
    int y = display.height()/2-5;
    display.drawString(x, y, text);
    display.display();
}

void displayBabyCrying() {
    display.clear();

    display.drawXbm(0, 0, 60, 60, baby_cry_bits);
    display.setTextAlignment(TEXT_ALIGN_RIGHT);
    int x = display.width();
    int y = display.height()-12;
    display.drawString(x, y, "Baby Crying");
    display.display();
}

void displaySiren() {
    display.clear();

    display.drawXbm(0, 0, 60, 60, siren_bits);
    display.setTextAlignment(TEXT_ALIGN_RIGHT);
    int x = display.width();
    int y = display.height()-12;
    display.drawString(x, y, "Baby Crying");
    display.display();

}

void setup() {
    display.init();
}

void loop() {
    display.clear();

    display.drawXbm(0, 0, 60, 60, telephone_bits);
    display.setTextAlignment(TEXT_ALIGN_RIGHT);
    int x = display.width();
    int y = display.height()-12;
    display.drawString(x, y, "Baby Crying");
    display.display();

}
