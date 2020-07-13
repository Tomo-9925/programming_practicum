#include <stdio.h>
#include <stdlib.h>

int couldnt_reserve(int *data) {
  if(data == NULL) {
    printf("メモリが確保できません．\n");
    return 1;
  }
  return 0;
}

int main(void) {
  int *data;
  int histgram[10] = {0};
  int size = 10;
  int count = 0;
  int tmp, i, j, k;

  data = malloc(sizeof(int) * size);
  if(couldnt_reserve(data)) return 1;

  while(1) {
    // 再確保処理
    if(count>=size && count%size==0) {
      data = realloc(data, sizeof(int)*((count/size+1)*size));
      if(couldnt_reserve(data)) return 1;
    }

    // 入力処理
    printf("数値を入力して下さい: ");
    scanf("%d", &tmp);

    // 中断処理
    if(tmp==0) break;

    data[count] = tmp;

    count++;
  }

  // 入力値(data)郡 -> ヒストグラム数値範囲(histgram)郡変換処理
  for(i=0; i<count; i++) {
    k = 10;
    for(j=0; j<10; j++) {
      if(data[i]<=k) {
        histgram[j]++;
        break;
      }
      k += 10;
    }
  }

  // 出力処理
  for(i=9; i>=0; i--) {
    printf("%3d - %3d: ", (i*10)+1, (i*10)+10);
    for(j=1; j<=histgram[i]; j++) printf("*");
    printf("\n");
  }

  // 開放処理
  free(data);

  return 0;
}