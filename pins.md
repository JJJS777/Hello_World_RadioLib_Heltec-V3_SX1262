
# Pins for LoRa Chip and OLED on Heltec V3

## New ESP32 Heltec Board with LoRa SX1262

### According to the schematic Diagram (WORKS)
#### LoRa sx1262
```cpp
lora_nss: 8 //same as cs
lora_rst: 12 //same as nrst
dio1: 14 //same as irq, first interrupt/GPIO
lora_busy: 13 //same as gpio Pin, second interrupt/GPIO
lora_sck: 9
lora_miso: 11
lora_mosi: 10
 ```

#### OLED
```
scl 18
sda 17
rstOlcd 21

// old u8x8 lib
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(scl, sda, rstOlcd);

// new u8g2 lib
U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* clock=*/18, /* data=*/17, /* reset=*/21);
```

### According to scan and pins_arduino.h (WRONG)
+ pins_arduino.h got [changed](https://github.com/Heltec-Aaron-Lee/WiFi_Kit_series/commit/b624b342921ac69caf7fb4fa8ca8c4e38e02748f) after

```cpp
MOSI: 11
MISO: 13
SCK: 12
SS: 10
```

## RadioLib Example
```cpp
// SX1262 has the following connections:
// NSS pin:   10 (cs Pin)
// DIO1 pin:  2 (irq Pin)
// NRST pin:  3 (rst pin) 
// BUSY pin:  9 (gpio Pin)
// SX1262 radio = new Module(10, 2, 3, 9);
// Module(cs, irq, rst, gpio) 
```
