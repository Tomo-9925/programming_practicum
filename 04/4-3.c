#include <stdio.h>

int count(char *str);
void reverse(char *str);

int main(void) {
  char array[50];
  int num;

  //文字入力
  printf("文字列を入力してください(2文字以上)\n");
  scanf("%s", array);

  //文字数をカウント
  num = count(array);
  printf("\n文字数 = %d\n", num);

  //文字を出力
  printf("入れ替え前\n");
  printf("%s\n", array);
  reverse(array);
  printf("入れ替え後\n");
  printf("%s\n", array);

  return 0;
}

int count(char *str) {
  int i = 0;

  while (*(str+i)!='\0') {
    i++;
  }

  return i;
}

void reverse(char *str) {
  char tmp[50];
  char *tmp_pt = tmp;
  int i = count(str);
  //int k = i - 1;
  int j;

  for (j=0; j<i; j++) {
    *(tmp_pt+j) = *((str+(i-1))-j);
    //k--;
  }

  for (j=0; j<i; j++) {
    *(str+j) = *(tmp_pt+j);
    }

  // str = tmp_pt;
}
