// Find the greatest common divisor of two integers

#include <stdio.h>

#define USE_RECURSIVE

int gcd(int a, int b)
{
#ifdef USE_RECURSIVE // Recursive
  if (b == 0) return a;
  return gcd(b, a%b);
#endif
  
#ifndef USE_RECURSIVE // Loop
  int r;
  
  while (b != 0) {
    r = a%b;
    a = b;
    b = r;
  }

  return a;
#endif
}

int main(void)
{
  int a, b;

  printf("Input two integers:\n");
  scanf("%d%d", &a, &b);
  printf("GCD of %d and %d is %d\n", a, b, gcd(a,b));

  return 0;
}
