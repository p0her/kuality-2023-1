#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char s[6][3];
	float ret = 0;
	printf("6�� ������ ������ �Է����ֽʽÿ�.\n");
	for (int i = 0; i < 6; i++) scanf("%s", s[i]);
	for (int i = 0; i < 6; i++) {
		if (!strcmp(s[i], "A+")) ret += 4.5;
		else if (!strcmp(s[i], "A")) ret += 4.0;
		else if (!strcmp(s[i], "B+")) ret += 3.5;
		else if (!strcmp(s[i], "B")) ret += 3.0;
		else if (!strcmp(s[i], "C+")) ret += 2.5;
		else if (!strcmp(s[i], "C")) ret += 2.0;
		else if (!strcmp(s[i], "D+")) ret += 1.5;
		else if (!strcmp(s[i], "D")) ret += 1.0;
		else if (!strcmp(s[i], "F")) ret += 0.0;
		else {
			printf("�߸��� �Է��Դϴ�.");
			return 0;
		}
	}
	ret /= 6.0;
	if (ret >= 4.5) printf("A+");
	else if (ret < 4.5 && ret >= 4.0) printf("A");
	else if (ret < 4.0 && ret >= 3.5) printf("B+");
	else if (ret < 3.5 && ret >= 3.0) printf("B");
	else if (ret < 3.0 && ret >= 2.5) printf("C+");
	else if (ret < 2.5 && ret >= 2.0) printf("C");
	else if (ret < 2.0 && ret >= 1.5) printf("D+");
	else if (ret < 1.5 && ret >= 1.0) printf("D");
	else printf("F");	
}
