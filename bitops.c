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

// a is unsigned, so 0 is filled when a right shifts.
int count_set_bits(unsigned int a)
{
	int count = 0;

	while (a) {
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

// Use shift to implement multiplication
unsigned short shift_mul(unsigned char a, unsigned char b)
{
	unsigned short result = 0;

	while (a) {
		if (a & 1) {
			result += b;
		}

		a >>= 1;
		b <<= 1;
	}

	return result;
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

	a = 0xffffffff;
	printf("0x%x has %d set bits\n", a, count_set_bits(a));

	x = 9;
	printf("Is %d power of 2?: %d\n", x, is_power_of_two(x));

	a = 7;
	b = 11;
	printf("%d x %d is %d\n", a, b, shift_mul(a, b));
	return 0;
}
