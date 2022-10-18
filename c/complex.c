#include <stdio.h>
#include <math.h>

struct complex {
  float real;
  float imag;
};

float cabs(struct complex c);
float angle(struct complex c);

struct complex from_polar(float abs, float angle);

float cabs(struct complex c) {
  return sqrt(c.real * c.real + c.imag * c.imag);
}

float angle(struct complex c) {
  return atan2(c.imag, c.real);
}

struct complex from_polar(float abs, float angle) {
  struct complex c = { };
  c.real = abs * cos(angle);
  c.imag = abs * sin(angle);
  return c;
}

int main(){
  float abs = 0, phi = 0;
  printf("Inserire il modulo e l'angolo: ");
  scanf("%f %f", &abs, &phi);
  struct complex c = from_polar(abs, phi);
  printf("In coordinate cartesiane risulta: %.2f + i%.2f\n", c.real, c.imag);
  printf("In coordinate polari risulta: M = %.2f, arg = %.2f\n",
         cabs(c), angle(c));
  return 0;
}

