// Find the greatest common divisor of two integers
#include <stdio.h>

int gcd(int a, int b)
{
#if 1
	//Recursive
	if (b == 0) return a;
	return gcd(b, a%b);

#else
	// Loop
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
