#include <stdio.h>
#include <string.h>

/*int main() {
    static FILE *pita;
    char CC;
    int retval;
    pita = stdin;
	retval = fscanf(pita, "%c", &CC);
	retval = fscanf(pita, "%c", &CC);
    printf("CC ke-2 nya : %c\n", CC);
    printf("retvalnya : %d\n", retval);
    return 0;
} */

int main() {
	int ans = 0 % 2;
	printf("%d", ans);
	return 0;
}
