#include <stdio.h>

typedef struct {
  int odd[20]; //奇数
  int even[20]; //偶数
} NUMBER;

int main() {
  int i = 0; //奇数カウンター
  int j = 0; //偶数カウンター
  int k, tmp;
  FILE *fp;
  NUMBER number;

  //テキストファイルを読み込み、奇数と偶数を分ける。
  fp = fopen("../01/01number.txt","r");
  while(fscanf(fp, "%d", &tmp) != EOF) {
    if(1 == tmp % 2) {
      number.odd[i] = tmp;
      i++;
    } else {
      number.even[j] = tmp;
      j++;
    }
  }
  fclose(fp);

  //奇数と偶数を出力する。
  printf("奇数: ");
  for(k=0;k<i;k++) {
    printf("%d ", number.odd[k]);
  }
  printf("\b\n"); //一応最後のスペースを消す。

  printf("偶数: ");
  for(k=0;k<j;k++) {
    printf("%d ", number.even[k]);
  }
  printf("\b\n"); //一応最後のスペースを消す。

  return 0;
}
