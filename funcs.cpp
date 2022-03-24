#include <iostream>
#include "imageio.h"
#include <cmath>

bool isValid(int i, int j)
{
  return i < MAX_H && j < MAX_W;
}

void original(std::string fileName)
{
  std::string input = fileName;
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int out[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }
  writeImage("outImage.pgm",out, h, w);
}


void invert(std::string fileName)
{
  std::string input = fileName;
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int out[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = abs(img[row][col] - 255);
    }
  }
  writeImage("taskA.pgm",out, h, w);
}

void invertRHalf(std::string fileName)
{
  std::string input = fileName;
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int out[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      int colorVal = img[row][col];
      if (col > ((w/2) - 1)){ colorVal = abs(img[row][col] - 255); }
      out[row][col] = colorVal;
    }
  }
  writeImage("taskB.pgm",out, h, w);
}

void wBox(std::string fileName)
{
  std::string input = fileName;
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int out[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }
  int iStart = h/4, iEnd = iStart*3, jStart = w/4, jEnd = jStart*3;
  for (int i = iStart; i <= iEnd; i++)
  {
    for (int j = jStart; j < jEnd; j++)
    {
      out[i][j] = 255;
    }
  }
  writeImage("taskC.pgm",out, h, w);
}

void frame(std::string fileName)
{
  std::string input = fileName;
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int out[MAX_H][MAX_W];

  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = img[row][col];
    }
  }
  int iStart = h/4, iEnd = iStart*3, jStart = w/4, jEnd = jStart*3;
  for (int i = iStart; i <= iEnd; i++)
  {
    for (int j = jStart; j <= jEnd; j++)
    {
      if (i == iStart || i == iEnd || j == jStart || j == jEnd)
      {
        out[i][j] = 255;
      }
    }
  }
  writeImage("taskD.pgm",out, h, w);
}

void scale2x(std::string fileName)
{
  std::string input = fileName;
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int out[MAX_H][MAX_W];

  for (int i = 0; i < h * 2; i++)
  {
    for (int j = 0; j < w * 2; j++)
    {
      out[i][j] = img[i / 2][j / 2];
    }
  }
  writeImage("taskE.pgm",out, h*2, w*2);
}

void pixelate(std::string fileName)
{
  std::string input = fileName;
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int out[MAX_H][MAX_W];

  for(int row = 0; row < h; row = row + 2) {
    for(int col = 0; col < w; col = col + 2) {
      int avg = img[row][col];
      out[row][col] = avg;
      if (isValid(row + 1, col))
      { 
        avg = (img[row][col] + img[row + 1][col]) / 2;
        out[row + 1][col] = avg;
      }
      if (isValid(row + 1, col + 1)){ out[row + 1][col + 1] = avg; }
      if (isValid(row, col + 1)){ out[row][col + 1] = avg; }
    }
  }
  writeImage("taskF.pgm",out, h, w);
}
