#include <stdio.h>

void swapstr(char *str1, char *str2);
int max(char *str1, char *str2);

int main(void) {
  char str1[50];
  char str2[50];

  //文字列の入力
  printf("2つの文字列を入力してください\n");
  scanf("%s", str1);
  scanf("%s", str2);

  printf("\n入れ替え前\n");
  printf("配列str1 = %s\n", str1);
  printf("配列str2 = %s\n", str2);

  swapstr(str1, str2);

  printf("\n入れ替え後\n");
  printf("配列str1 = %s\n", str1);
  printf("配列str2 = %s\n", str2);

  return 0;
}

void swapstr(char *str1, char *str2) {
  char tmp[50];
  char *tmp_pt = tmp;
  int i, count;

  count = max(str1, str2);

  for(i=0; i<count; i++) {
    *(tmp_pt+i) = *(str1+i);
    *(str1+i) = *(str2+i);
    *(str2+i) = *(tmp_pt+i);
  }
}

int max(char *str1, char *str2) {
  int i=0, j=0;

  while (*(str1+i)!='\0') {
    i++;
  }

  while (*(str2+j)!='\0') {
    j++;
  }

  //数値が大きい方を返す
  if (i<j) {
    return j;
  } else {
    return i;
  }
}
