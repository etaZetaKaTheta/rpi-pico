#include <pico/stdlib.h>
#include <string.h>

#include "digitalIO.h"
#include "timing.h"

#include "spi.h"
#include "ILI9225.h"

#define SCREEN_W ILI9225_LCD_WIDTH
#define SCREEN_H ILI9225_LCD_HEIGHT

int main()
{
  digitalIO_init();
  timing_init();
  timing_start_timer();

  spi0_init();
  spi0_set_mode(SPI_MODE0);
  //spi0_setspeed(2);

  ILI9225_init();
  ILI9225_clrScreen();

  uint16_t colBuf[] =
  {
    0xf00f, 0xf00f, 0xf00f, 0xf00f, 0xf00f, 0xf00f, 0xf00f, 0xf00f, 0xf00f, 0xf00f, 0xf00f, 0xf00f, 0xf00f, 0xf00f, 0xf00f, 0xf00f, 0xf00f, 0xf00f,
    0x0f0f, 0x0f0f, 0x0f0f, 0x0f0f, 0x0f0f, 0x0f0f, 0x0f0f, 0x0f0f, 0x0f0f, 0x0f0f, 0x0f0f, 0x0f0f, 0x0f0f, 0x0f0f, 0x0f0f, 0x0f0f, 0x0f0f, 0x0f0f,
    0x00ff, 0x00ff, 0x00ff, 0x00ff, 0x00ff, 0x00ff, 0x00ff, 0x00ff, 0x00ff, 0x00ff, 0x00ff, 0x00ff, 0x00ff, 0x00ff, 0x00ff, 0x00ff, 0x00ff, 0x00ff,
  };

  unsigned short buf[SCREEN_W * SCREEN_H * 2];

  memset(buf, 1, SCREEN_W * SCREEN_H * 2);

  /*for (int x = 0; x < SCREEN_W; x++)
  {
    buf[SCREEN_H / 2 * SCREEN_W + x] = 0xffff;
  }

  for (int x = 0; x < SCREEN_H; x++)
  {
    buf[SCREEN_W * x + SCREEN_W / 2] = 0x611f;
  }*/

  for (int i = 0; i < sizeof(colBuf) / sizeof(uint16_t); i += 16)
  {
    buf[i] = colBuf[i];
  }

  ILI9225_transfer((unsigned char*)colBuf, SCREEN_W * SCREEN_H * 2);
}

