#include <stdio.h>
#define COUNT 15

int main(void) {
	int num[COUNT], tmp;
	int i;
	FILE *fp;

	//ファイルを開く(読み込みモード)処理
	if ((fp=fopen("01number.txt", "r"))==NULL) {
		printf("File is not found.\n");
		return 1;
	}

	i = 0;

	while(fscanf(fp, "%d", &tmp) != EOF){
		num[i]=tmp; //配列(num[i])に格納
		i++;
	}

	while(i>0) {
		i--;
		printf("%d ", num[i]);
	}

	printf("\n");	

	fclose(fp);

	return 0;
}
