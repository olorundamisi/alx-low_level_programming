#include <stdio.h>
#include <string.h>

int main(void) {
	char str[55];

	strcpy(str, "\"Programming is like building a multilingual puzzle");	/* strcpy()	from string.h */
	puts(str);								/* puts()	from stdio.h */

	return 0;
}
