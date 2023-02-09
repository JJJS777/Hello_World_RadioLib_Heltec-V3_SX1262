# Hello_World_RadioLib_Heltec-V3_SX1262
Hello World example code for the new Heltec WiFi LoRa 32 (V3) board with LoRa SX1262 chip

## Setup
I use, as metioned, the [Heltec WiFi LoRa 32 (V3)](https://heltec.org/project/wifi-lora-32-v3/) and vsc with the platformio plugin.
My PlatformIO Configuration looks like this and can be found [her](platformio.ini).

```ini
[env:esp32dev]
platform = espressif32
board = esp32-s3-devkitc-1
framework = arduino
lib_deps = 
	olikraus/U8g2@^2.34.13
	jgromes/RadioLib@^5.6.0
```
Note: i don't use a heltec board, as you can see here (```board = esp32-s3-devkitc-1```) and, because of that i didn't rely on the ```pins_arduino.h```in ```platformio\packages\framework-arduinoespressif32\variants\heltec_WIFI_LoRa_32_V3```.


## Pins for LoRa Chip and OLED on Heltec WiFi LoRa 32 (V3)
### According to the [schematic Diagram](https://resource.heltec.cn/download/WiFi_LoRa32_V3/HTIT-WB32LA(F)_V3_Schematic_Diagram.pdf) (WORKS)
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
oled_scl: 18
oled_sda: 17
oled_rst: 21

// new u8g2 library
U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* clock=*/18, /* data=*/17, /* reset=*/21);

// old u8x8 library
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(scl, sda, rstOlcd);
```

### According to [scan](examples/helper) and [pins_arduino.h](https://github.com/Heltec-Aaron-Lee/WiFi_Kit_series/blob/master/esp32/variants/WIFI_LoRa_32_V3/pins_arduino.h) (WRONG)
+ **NOTE**: pins_arduino.h got [changed](https://github.com/Heltec-Aaron-Lee/WiFi_Kit_series/commit/b624b342921ac69caf7fb4fa8ca8c4e38e02748f)

```
MOSI: 11
MISO: 13
SCK: 12
SS: 10
```

### Pins from the RadioLib Example
```
SX1262 has the following connections:
NSS pin:   10 (cs Pin)
DIO1 pin:  2 (irq Pin)
NRST pin:  3 (rst pin) 
BUSY pin:  9 (gpio Pin)
SX1262 radio = new Module(10, 2, 3, 9);
Module(cs, irq, rst, gpio) 
```

hmu if you have any questions, maybe i can help (::