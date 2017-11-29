#include <dht.h>
 #include <OLED_I2C.h> 
OLED  myOLED(0, 2, 8);
extern uint8_t RusFont[];
DHT sensor = DHT();
String msg = "";
int solid = false;

void error() {
  myOLED.clrScr();
  myOLED.print("JIB<RF", CENTER, 28);
  myOLED.update();
  delay(500);
  myOLED.clrScr();
  delay(500);
  myOLED.print("JIB<RF", CENTER, 28);
  myOLED.update();
  delay(500);
  myOLED.clrScr();
  delay(500);
  myOLED.print("JIB<RF", CENTER, 28);
  myOLED.update();
  delay(500);
  myOLED.clrScr();
  delay(500);
  sensor.attach(2);
}

void setup()
{
    myOLED.begin();
    myOLED.setFont(RusFont);
    sensor.attach(2);
    //
    // после подачи питания ждём секунду до готовности сенсора к работе
    delay(1000);
}
 
void loop()
{
    // метод update заставляет сенсор выдать текущие измерения
    sensor.update();
    myOLED.clrScr();
    switch (sensor.getLastError())
    {
        case DHT_ERROR_OK:
            char msg[128];
            sprintf(msg, "NTVGTHFNEHF = %dC",
                    sensor.getTemperatureInt());
            myOLED.print(msg, CENTER, 0);
            sprintf(msg, "DKF:YJCNM = %d%%",
                    sensor.getHumidityInt());
            myOLED.print(msg, CENTER, 12);
            break;
        case DHT_ERROR_START_FAILED_1:
            error();
            break;
        case DHT_ERROR_START_FAILED_2:
            error();
            break;
        case DHT_ERROR_READ_TIMEOUT:
            error();
            break;
        case DHT_ERROR_CHECKSUM_FAILURE:
            error();
            break;
    }
    solid = digitalRead(5);
    if (solid) {
      myOLED.print("NHT<ETNCZ", CENTER, 36);
      myOLED.print("GJKBD", CENTER, 48);
    }
    myOLED.update();

    delay(1000);
}
