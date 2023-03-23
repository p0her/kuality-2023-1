#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int n1, n2, n3;
	char c;
	printf("Input Number : ");
	scanf(" %d %d %d", &n1, &n2, &n3);
	printf("Input Character : ");
	scanf(" %c", &c);

	switch (c) {
	case '+':
		printf("%d\n", n1 + n2 + n3);
		break;
	case '-':
		printf("%d\n", n1 - n2 - n3);
		break;
	case '/':
		printf("%d\n", n1 / n2 / n3);
		break;
	case '*':
		printf("%d\n", n1 * n2 * n3);
		break;
	default:
		printf("Invalid operator");
		break;
	}
}
