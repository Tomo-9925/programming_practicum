#include <stdio.h>

typedef struct strings {	//構造体の定義
	char ch1[20];
	char ch2[20];
} STRINGS;

int main(void) {
	STRINGS input;
	char out[40];
  int i;
	int j;

	STRINGS *pt_input = &input;
	char *pt_out = &out[0];

	//以降の処理は、pt_input/pt_outから領域を参照
	printf("１つ目の文字列: ");
	scanf("%s", input.ch1);	//ポインタ変数を利用しinput.ch1に格納
	printf("2つ目の文字列: ");
	scanf("%s", input.ch2);	//ポインタ変数を利用しinput.ch2に格納

	//ch1,ch2の順に文字列を結合し、ポインタ変数を利用してoutに格納
	for(j=0; *(pt_input->ch1+j)!='\0'; j++) {
		*(pt_out+j) = *(pt_input->ch1+j);
	}
	for (i=0; *(pt_input->ch2+i)!='\0'; i++) {
		*(pt_out+j) = *(pt_input->ch2+i);
		j++;
	}

	printf("結合した文字列: %s\n", &out[0]);

	return 0;
}
