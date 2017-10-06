// Compute factoral
#include <stdio.h>

unsigned int factoral(unsigned int n)
{
#if 1
	// Recursive
	if (n == 0) return 1;
	return n * factoral(n-1);

#else
	// Non-recursive
	unsigned int ret = 1; // 0! = 1, 1! = 1

	while (n > 1) {
		ret *= n;
		n--;
	}

	return ret;
#endif
}

int main(void)
{
	int i;
	
	for (i = 0; i < 7; i++) {
		printf("%d\n", factoral(i));
	}

	return 0;
}
