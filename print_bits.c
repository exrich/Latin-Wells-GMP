#include <stdio.h>

print_bits(unsigned short int c)
{
  unsigned short int i;

  for (i = 1 << 15; i != 0; i >>= 1) {
    if (i&c) putchar('1'); else putchar('0');
  }
}