#include <Arduino.h>
#include <SPI.h>
#include <U8g2lib.h>

#define oled_scl 18
#define oled_sda 17
#define oled_rst 21

U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* clock=*/oled_scl, /* data=*/oled_sda, /* reset=*/oled_rst);
// U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // All Boards without Reset of the Display
// U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ 16, /* data=*/ 17, /* reset=*/ U8X8_PIN_NONE);   // ESP32 Thing, pure SW emulated I2C

void setup()
{
  Serial.begin(9600);
  while (!Serial)
    ;
  Serial.println("OLED Test");
  u8g2.begin();
}

void loop()
{
  u8g2.firstPage();
  do
  {
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.drawStr(0, 24, "Hello World (::");
  } while (u8g2.nextPage());
}
