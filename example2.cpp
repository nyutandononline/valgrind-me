#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
char *lower;
 
char *to_lower (const char *str)
{
	char *l = strdup (str);
	char *c;
 
	for (c = l; *c; c++) {
		if (isupper(*c))
			*c = tolower(*c);
	}
 
	return l;
}
 
int main (int argc, char *argv[])
{
	lower = to_lower (argv[1]);
 
	while (*lower)
		putchar (*(lower++));
	puts ("");
 
	return 0;
}
