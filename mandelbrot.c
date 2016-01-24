#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/** Dwell cut-off for drawing with ' ' */
#define LEVEL_1 10

/** Dwell cut-off for drawing with '.' */
#define LEVEL_2 20

/** Dwell cut-off for drawing with ':' */
#define LEVEL_3 30

/** Dwell cut-off for drawing with '-' */
#define LEVEL_4 40

/** Dwell cut-off for drawing with '=' */
#define LEVEL_5 50

/** Dwell cut-off for drawing with '+' */
#define LEVEL_6 60

/** Dwell cut-off for drawing with '*' */
#define LEVEL_7 70

/** Dwell cut-off for drawing with '#' */
#define LEVEL_8 80

/** Dwell cut-off for drawing with '%' */
#define LEVEL_9 90

double magnitude(double realCopy, double imagCopy){
  double mag = sqrt((realCopy * realCopy) + (imagCopy * imagCopy));
  return mag;
}

int testPoint( double cReal, double cImag)
{
  printf("%f %f\n", cReal, cImag);
  int dwell = 0;
  double realCopy = cReal;
  double imagCopy = cImag;
  double realWork = cReal;
  double imagWork = cImag;

  while (dwell < 90 ){
    realWork = realCopy;
    imagWork = imagCopy;
    realCopy = (realWork * realWork) - (imagWork * imagWork) + realWork;
    imagCopy = (realWork * imagWork) + (imagWork * realWork) + imagWork;
    if (magnitude(realCopy, imagCopy) > 2 ){
      break;
    }
    dwell++;
  }
  return dwell;
}

char dwellSymbol( int dwell )
{
  char dwellSymbol = ' ';
  if(dwell > LEVEL_1){
    dwellSymbol = '.';
  }
  if(dwell > LEVEL_2){
    dwellSymbol = ':';
  }
  if(dwell > LEVEL_3){
    dwellSymbol = '-';
  }
  if(dwell > LEVEL_4){
    dwellSymbol = '=';
  }
  if(dwell > LEVEL_5){
    dwellSymbol = '+';
  }
  if(dwell > LEVEL_6){
    dwellSymbol = '*';
  }
  if(dwell > LEVEL_7){
    dwellSymbol = '#';
  }
  if(dwell > LEVEL_8){
    dwellSymbol = '%';
  }
  if(dwell == LEVEL_9){
    dwellSymbol = '@';
  }
  return dwellSymbol;
}

void drawFigure( double minReal, double minImag, double size )
{
  double cReal = minReal;
  double cImag = minImag;
  double horUnit = size / 70;
  double verUnit = size / 35;
  
  for(int i = 0; i <= 35; i++){
    for(int j = 0; j <= 70; j++){
      int current = testPoint(cReal, cImag + size);
      char c = dwellSymbol(current);
      printf("%c", c);
      cReal += horUnit;
    }
    cReal = minReal;
    printf("\n");
    cImag -= verUnit;
  }
}

/**
   Starting point for the program, scans input and builds image based on Mandelbrot set.
 */
int main()
{ 

  double minReal = 0;
  double minImag = 0;
  double size = 0;
  
  printf("Minimum real: ");
  if (scanf("%lf", &minReal) != 1){
    printf("Invalid input");
    exit(1);
  }
  
  printf("Minimum imaginary: ");
    if (scanf("%lf", &minImag) != 1){
    printf("Invalid input");
    exit(1);
  }
  
  printf("Size: ");
    if (scanf("%lf", &size) != 1){
    printf("Invalid input");
    exit(1);
  }
  
  drawFigure(minReal, minImag, size);
  
  exit(0);
}