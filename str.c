// String operations
#include <stdio.h>
#include <string.h>

void reverse_str(char *str, int len)
{
#if 1
	int i, j;
	char ch;

	for (i = 0, j = len -1; i < j; i++, j--) {
		ch = str[i];
		str[i] = str[j];
		str[j] = ch;
	}
#else
	char *end = str + len - 1;
	char ch;

	while (str < end) {
		ch = *str;
		*str++ = *end;
		*end-- = ch;
	}
#endif
}


char *skip_space(char **p)
{
	while (**p == ' ') {
		(*p)++;
	}

	return *p;
}

void reverse_words_in_str(char *str)
{
	// First reverse the whole string
	reverse_str(str, strlen(str));

	// Reverse each word in the string
	char *curr = str;

	str = skip_space(&curr);
	while (*curr) {
		++curr;
		if (*curr == ' ') {
			reverse_str(str, curr - str);
			str = skip_space(&curr);
		}
		else if ((*curr == '\0')) {
			reverse_str(str, curr - str);
		}
	}
}

int main(void)
{
	char mystr[] = "    Hello   world ";
	printf("Orignial string:\n");
	printf("%s, length: %zd\n", mystr, strlen(mystr));

	reverse_words_in_str(mystr);
	printf("Reversed string: \n");
	printf("%s, length: %zd\n", mystr, strlen(mystr));

	return 0;
}
