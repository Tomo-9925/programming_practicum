#include <stdio.h>

int main(void) {
	char ch[100];
	char *pt;
	int i;

	//文字列の入力処理 (配列chに格納)
	printf("文字列を入力してください。\n");
	fgets(ch, 100, stdin);

	pt = &ch[0];	//ポインタ変数に配列のアドレスを設定

	for(i=0; *(pt+i)!='\n'; i++);

	//入力した文字列を逆順に出力 (以降は，ポインタ変数ptを利用)
	printf("入力文字列を逆順に出力します。\n");
	for (i=i-1; i>=0; i--) {
		printf("%c", *(pt+i));
	}
	printf("\n");

	return 0;
}
