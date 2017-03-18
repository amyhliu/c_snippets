// Bitwise operations

#include <stdio.h>


#define set_bit(x, n) (x |= (1 << n))
#define clr_bit(x, n) (x &= ~(1 << n))

void swap_int(int *a, int *b)
{
  *a = *a ^ *b;
  *b = *a ^ *b; // *a ^ *b ^ *a = *b
  *a = *a ^ *b; // *a ^ *b ^ *b = *a
}

int count_set_bits(int a)
{
  int i;
  int count = 0;
  
  for (i = 0; a; i++) {
    if (a & 1) {
      count++;
    }
    a >>= 1;
  }

  return count;
}

int is_power_of_two(int x)
{
  return ((x & (x - 1)) == 0);
}



int main(void)
{
  int x = 0;
  
  set_bit(x, 2);
  printf("%x\n", x);

  clr_bit(x, 2);
  printf("%x\n", x);

  int a = 1, b = 2;
  swap_int(&a, &b);
  printf("a: %d, b: %d\n", a, b);

  printf("number of set bits: %d\n", count_set_bits(10));

  x = 9;
  printf("%d is power of 2: %d\n", x, is_power_of_two(x));
  
  return 0;
}
