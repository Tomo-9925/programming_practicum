#include <stdio.h>

int main(void) {
	int num1, num2, tmp;
	FILE *fp;

	//Write number
	printf("数値1の入力: ");
	scanf("%d", &num1);
	printf("数値2の入力: ");
	scanf("%d", &num2);

	//Set num1 to small number

	if(num1>num2) {
		tmp = num1;
		num1 = num2;
		num2 = tmp;
	}

	//Print to 01range.txt
	fp = fopen("01range.txt", "w");
	while(num1<=num2) {
		fprintf(fp, "%d\n", num1);
		num1++;
	}
	fclose(fp);

	return 0;
}
