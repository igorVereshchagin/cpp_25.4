#include "ram.h"

int ram_buf[8];

void write(int buf[8])
{
  for (int i = 0; i < 8; i++)
    ram_buf[i] = buf[i];
}

void read(int buf[8])
{
  for (int i = 0; i < 8; i++)
    buf[i] = ram_buf[i];
}