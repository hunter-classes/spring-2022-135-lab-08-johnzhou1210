#include <iostream>
#include "imageio.h"
#include "funcs.h"

int main()
{
  invert("caesar.pgm");
  invertRHalf("caesar.pgm");
  wBox("caesar.pgm");
  frame("caesar.pgm");
  scale2x("caesar.pgm");
  pixelate("caesar.pgm");
  return 0;
}
