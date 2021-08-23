#include<stdio.h>
#include<string.h>
int main(void) {
	int i, j, key;
	char s[6] = { 0 };
	while (1) {
		scanf("%s", s);
		if (s[0] == '0')
			break;
		key = 0;
		if (strlen(s) % 2 == 0) {
			for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
				if (s[i] != s[j]) {
					key = 1;
					break;
				}
			}
		}
		else {
			for (i = 0, j = strlen(s) - 1; i != j; i++, j--) {
				if (s[i] != s[j]) {
					key = 1;
					break;
				}
			}
		}

		if (key == 1)
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}