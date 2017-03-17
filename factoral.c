// Compute factoral

#include <stdio.h>


int factoral(int n)
{
#if 1
  // Recursive
  if (n == 0) return 1;
  
  return n * factoral(n-1);
#endif

#if 0
  // Non-recursive
  int i;
  int ret = 1;

  if (n == 0) return 1;
  
  for (i = 1; i <= n; i++) {
      ret = ret * i;
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
