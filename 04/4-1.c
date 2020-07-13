#include <stdio.h>
#define COUNT 3

void input(int *array);
void sort(int *array);
void output(int *array);

int main(void) {
  //配列の宣言
  int data[COUNT];

  input(data);
  sort(data);
  output(data);

  return 0;
}

void input(int *array) {
  printf("3つの数字を入力してください\n");
  scanf("%d%d%d", array, array+1, array+2);
}

void sort(int *array) {
  int i, j, tmp;
  for(i=0; i<COUNT; i++) {
    for(j=i+1; j<COUNT; j++) {
      if(*(array+i)>*(array+j)) {
        tmp = *(array+i);
        *(array+i) = *(array+j);
        *(array+j) = tmp;
      }
    }
  }
}

void output(int *array) {
  printf("並び替え結果\n");
  printf("%d %d %d\n", *array, *(array+1), *(array+2));
}
