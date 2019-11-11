#include <jlinker.h>
jlinker Joystick;
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);
MPU6050 accelgyro;
int16_t ax, ay, az;
int16_t gx, gy, gz;
char bufferX [20];
char bufferY [20];
char bufferZ [20];
int transmitted[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int distance = 0;
RF24 Nrf24l01(9, 10); // CE, CSN
const byte address[][6] = {"00001", "00002"};
void setup() {
  Joystick.pinSet();
  Nrf24l01.begin();
  Nrf24l01.openWritingPipe(address[1]); // 00002
  Nrf24l01.openReadingPipe(1, address[0]); // 00001
  Nrf24l01.setPALevel(RF24_PA_MIN);
  Nrf24l01.stopListening();
  Serial.begin(9600);
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
  Wire.begin();
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
  Fastwire::setup(400, true);
#endif
  accelgyro.initialize();

}

void loop() {
  digitalWrite(User_LED, HIGH);
  Nrf24l01.stopListening();
  transmitted[9] = map(Joystick.POT_2(), 0, 1023, 255, 0);
  Serial.println(transmitted[9]);
  decide();
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  Nrf24l01.write(&transmitted, sizeof(transmitted));
  Nrf24l01.startListening();
  if (Nrf24l01.available())
    digitalWrite(User_LED, HIGH);
  Nrf24l01.read(&distance, sizeof(distance));

  sprintf(bufferX, " Robolink Market   ");
  sprintf(bufferY, "     Jlinker ");
  sprintf(bufferZ, "    Rodeo-2.4G");
  u8g.firstPage();
  do {
    draw();
  } while ( u8g.nextPage() );
}

int decide ()
{
  for (int i = 0; i <= 8; i++)
    transmitted[i] = 0;
  if (Joystick.Switch_1() == 1 && Joystick.Switch_2() == 1)
  {
    transmitted[0] = 1;
  }


  if (Joystick.Switch_1() == 0 && Joystick.Switch_2() == 1)
  { transmitted[1] = 1;
  }
  if (Joystick.Switch_1() == 1 && Joystick.Switch_2() == 0)
  { transmitted[2] = 1;
  }

  if (Joystick.Switch_1() == 0 && Joystick.Switch_2() == 0)
  {
    if ( Joystick.joyRightY() > 530)
    { transmitted[3] = 1;
    }

    if ( Joystick.joyRightY() < 370)
    { transmitted[4] = 1;
    }
    if (Joystick.joyLeftX() > 550 )
    { transmitted[5] = 1;
    }
    if (Joystick.joyLeftX() < 490)
    { transmitted[6] = 1;
    }
    if (Joystick.Button_3() == 0 && Joystick.Button_4() == 0 )
    {
      accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

      if (ay < -3000)
      { transmitted[3] = 1;
      }
      if (ay > 5000)
      { transmitted[4] = 1;
      }
      if ( ax < -4500)
      {
        transmitted[6] = 1;
      }

      if ( ax > 4000)
      { transmitted[5] = 1;
      }
    }
  }
  if (Joystick.Button_1() == 0 )
  { transmitted[7] = 1;
  }
  if (Joystick.Button_2() == 0 )
  { transmitted[8] = 1;
  }
 
}
void draw(void) {
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr( 0, 20, bufferX);
  u8g.drawStr( 0, 40, bufferY);
  u8g.drawStr( 0, 60, bufferZ);
}
