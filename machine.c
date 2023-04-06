#include <stdio.h>
#include <stdlib.h>

#define MONEY_TYPE_CNT 8
#define MONEY_COUNT_CNT 8

int all_money = 0;
int current_money = 0;
int count_drink[6] = {0, 0, 0, 0, 0};

void draw() { for(int i = 0; i < 20; i++) { printf("="); } printf("\n"); }

int money_type[MONEY_TYPE_CNT+1] = {1,10,50,100,500,1000,5000,10000,50000};
int money_count[MONEY_COUNT_CNT+1] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

void state_file_read() {
	int count = 0;
	FILE *file = NULL;
	file = fopen("./state.txt", "r");
	if(file != NULL) {
		while(!feof(file)) { 
			char str[1024];
			char *pstr;
			pstr = fgets(str, sizeof(str), file);
			if(count == 0) { all_money = strtoul(pstr, NULL, 0); }
			if(0 < count && count <= 5) { count_drink[count - 1] = strtoul(pstr, NULL, 0); }
			count++;
		}
		fclose(file);
	} else {
		exit(1);
	}
	printf("%d\n", all_money);
	for(int i = 0; i < 5; i++) printf("%d\n", count_drink[i]);
}

void print_menu() {
	printf("All money : %d\n", all_money);
	printf("Current money : %d\n", current_money);
	draw();
	printf("1. input money\n");
	printf("2. return money\n");
	printf("3. choice drink\n");
	printf("4. exit\n");
	draw();
	printf(">> ");
}

void input_money() {
	int t;
	printf("Input money >> ");
	scanf("%d", &t);
	all_money += t;
	current_money += t;
	printf("success\n");
}

void return_money() {
	printf("Current money : %d\n", current_money);
	for(int i = MONEY_TYPE_CNT; i >= 0; i--) {
		if(current_money == 0) break;
		int temp = money_type[i];
		printf("%d \n", money_count[i]);
		money_count[i] += ((current_money) / temp);
		printf("%d \n", ((current_money) / temp) * money_count[i]);
		all_money -= (((current_money) / temp) * money_type[i]);
		current_money -= (((current_money) / temp) * money_type[i]);
	}
	for(int i = MONEY_TYPE_CNT; i >= 0; i--) printf("%d원 : %d\n", money_type[i], money_count[i]);
	FILE *file = fopen("./state.txt", "w");
	/* 쓰기는 나중에 하겠습니다,,, */
	exit(0);
}
void sel_drink() {
	while(1) {
		int flag = 0;
		int sel;
		printf("Select drink!\n");
		draw();
		printf("0. exit\n");
		printf("1. coke (200) (남은 개수 : %d)\n", count_drink[0]);
		printf("2. max coffie (200) (남은 개수 :%d)\n", count_drink[1]);
		printf("3. monster (black) (100) (남은 개수 : %d)\n", count_drink[2]);
		printf("4. hot six (300) (남은 개수 : %d)\n", count_drink[3]);
		printf("5. red bull (300) (남은 개수 : %d)\n", count_drink[4]);
		draw();
		printf(">> ");
		scanf("%d", &sel);
		if(count_drink[sel - 1] <= 0) {
			printf("재고가 부족합니디.\n");
			continue;
		}
		switch(sel) {
			case 0:
				printf("byebye\n");
				return;
			case 1:
				if(current_money < 200) {
					printf("돈이 부족합니다!\n");
					break;
				}
				all_money += 200;
				current_money -= 200;
				count_drink[0]--;
				flag = 1;
				break;
			case 2:
				if(current_money < 200) {
					printf("돈이 부족합니다!\n");
					break;
				}
				all_money += 200;
				current_money -= 200;
				count_drink[1]--;
				flag = 1;
				break;
			case 3:
				if(current_money < 100) {
					printf("돈이 부족합니다!\n");
					break;
				}
				all_money += 100;
				current_money -= 100;
				count_drink[2]--;
				flag = 1;
				break;
			case 4:
				if(current_money < 300) {
					printf("돈이 부족합니다!\n");
					break;
				}
				all_money += 300;
				current_money -= 300;
				count_drink[3]--;
				flag = 1;
				break;
			case 5:
				if(current_money < 300) {
					printf("돈이 부족합니다!\n");
					break;
				}
				all_money += 300;
				current_money -= 300;
				count_drink[4]--;
				flag = 1;
				break;
			default:
				printf("Wrong input!\n");
				break;
		}
		if(flag) { printf("Success!!\n"); return; }
	}
}

int main() {
	state_file_read();
	while(1) {
		int sel;
		print_menu();
		scanf("%d", &sel);
		switch(sel) {
			case 1:
				input_money();
				break;
			case 2:
				return_money();
				break;
			case 3:
				sel_drink();
				break;
			default:
				printf("Wrong input!\n");
				break;
		}
	}
}
