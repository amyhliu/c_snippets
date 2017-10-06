// Compute and display Fibonacci series
#include <stdio.h>


// Print out Fibonacci series up to nth number and return the sum
int fib1(int n)
{
	int a = 0; // 1st number
	int b = 1; // 2nd number
	int c = 0;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		if (i <= 1) {
			c = i;
		}
		else {
			c = a + b;
			a = b;
			b = c;
		}

		sum += c;
		printf("%d, ", c);
	}

	printf("\n");
	return sum;
}

// Print out Fibonacci series until the last number is not greater than n
// and return sum.
int fib2(int n)
{
	int a = 0;
	int b = 1;
	int c = 0;
	int sum = 0;

	printf("%d, %d, ", a, b);
	c = a + b;
	sum += c;
	
	while (c <= n) {
		printf("%d, ", c);
		sum += c;
		a = b;
		b = c;
		c = a + b;
	}
	
	printf("\n");
	return sum;
}

// Compute the nth number using recursive method
int fib(int n)
{
	if (n <= 1) return n;
 	return (fib(n-2) + fib(n-1));
}

int main(void)
{
	printf("n = 0, sum = %d\n", fib1(0));
	printf("n = 1, sum = %d\n", fib1(1));
	printf("n = 2, sum = %d\n", fib1(2));
	printf("n = 3, sum = %d\n", fib1(3));
	printf("n = 10, sum = %d\n", fib1(10));

	printf("n = 0, sum = %d\n", fib2(0));
	printf("n = 1, sum = %d\n", fib2(1));
	printf("n = 2, sum = %d\n", fib2(2));
	printf("n = 3, sum = %d\n", fib2(3));
	printf("n = 20, sum = %d\n", fib2(20));

	printf("%d\n", fib(10));

  return 0;
}
  
