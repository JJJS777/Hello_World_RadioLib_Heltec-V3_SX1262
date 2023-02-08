# Hello_World_RadioLib_Heltec-V3_SX1262
Hello World example code for the new Heltec WiFi LoRa 32 (V3) board with LoRa SX1262 chip

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

hmu if you have any questions, maybe i can help (::