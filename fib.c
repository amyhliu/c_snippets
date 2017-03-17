// Compute and display Fibonacci series

#include <stdio.h>


// Print out Fibonacci series up to nth number and return the sum
int fib1(int n)
{
  int a = 0; // 1st number
  int b = 1; // 2nd number
  int c = 0;
  int i;
  int sum = 0;

  for (i = 0; i <= n; i++) {
    if (i <= 1) {
      c = i;
    }
    else {
      c = a + b;
      a = b;
      b = c;
    }

    sum += c;
    printf("%d ", c);
  }

  printf("\n");
  return sum;
}

// Compute the nth number using recursive method
int fib2(int n)
{
  if (n <= 1) return n;
  return (fib2(n-2) + fib2(n-1));
}

int main(void)
{
  printf("sum = %d\n", fib1(0));
  printf("sum = %d\n", fib1(1));
  printf("sum = %d\n", fib1(2));
  printf("sum = %d\n", fib1(10));

  printf("%d\n", fib2(10));

  return 0;
}
  
