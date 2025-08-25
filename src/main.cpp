#include <Arduino.h>
#include <GxEPD.h>
#include <GxGDE0213B1/GxGDE0213B1.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>


#include "BitmapGraphics.h"

#include <Fonts/FreeSansBold24pt7b.h>


GxIO_Class io(SPI, SS, 22, 21);
GxEPD_Class display(io, 16, 4);

void setup() {
  
  Serial.begin(9600);
  display.init();
  
  display.drawExampleBitmap(gImage_splash, 0, 0, 200, 200, GxEPD_BLACK);
  display.update();
  delay(3000);


}

void loop() 
{
  
  delay(5000);
}

void showPartialUpdate(float temperature)
{
  Serial.println("Updating display ...");
  String temperatureString = String(temperature,1);
  const char* name = "FreeSansBold24pt7b";
  const GFXfont* f = &FreeSansBold24pt7b;
  
  uint16_t box_x = 60;
  uint16_t box_y = 60;
  uint16_t box_w = 90;
  uint16_t box_h = 100;
  uint16_t cursor_y = box_y + 16;

  display.setRotation(45);
  display.setFont(f);
  display.setTextColor(GxEPD_BLACK);

  display.fillRect(box_x, box_y, box_w, box_h, GxEPD_WHITE);
  display.setCursor(box_x, cursor_y+38);
  display.print(temperatureString); 
  display.updateWindow(box_x, box_y, box_w, box_h, true);
}