#include <stdio.h>

// クイックソート関数
void quickS(char array[], int first, int last);

// 文字列をコピー
void cpStr(char *str1, char *str2);

// 文字数カウント関数
int strLen(char *str);

int main() {
  char str1[100], str2[100];
  char str1o[100], str2o[100];
  int len1, len2, i;

  // 文字列の入力
  printf("文字列1を入力してください。\n");
  scanf("%s", str1);
  printf("文字列2を入力してください。\n");
  scanf("%s", str2);

  // 文字数取得
  len1 = strLen(str1);
  len2 = strLen(str2);
  if(len1 != len2) {  // 文字数が異なったとき終了
    printf("文字列%sを並び替えて文字列%sを生成できません。\n", str1, str2);
    return 0;
  }

  // 文字列の複製
  cpStr(str1, str1o);
  cpStr(str2, str2o);

  // 文字列をソート
  quickS(str1, 0, len1-1);
  quickS(str2, 0, len2-1);

  // 文字列の比較
  for(i=0; i<len1; i++) {
    if(str1[i] != str2[i]){ //比較中異なったものが出てきたとき終了
      printf("文字列%sを並び替えて文字列%sを生成できません。\n", str1o, str2o);
      return 0;
    }
  }

  printf("文字列%sを並び替えて文字列%sを生成できます。\n", str1o, str2o);

  return 0;
}

// クイックソート関数
void quickS(char *array, int first, int last) {
  int left = first;
  int right = last;
  int pivot = array[last];
  int tmp;

  while(1) {
    while(array[left] < pivot) ++left;
    while(array[right] > pivot) --right;
    if(left < right) {
      tmp = array[left];
      array[left] = array[right];
      array[right] = tmp;

      ++left;
      --right;
    }
    else break;
  }
  if(first < left-1) quickS(array, first, left-1);
  if(right+1 < last) quickS(array, right+1, last);
}

// 文字列をコピー
void cpStr(char *str1, char *str2) {
  int i = 0;

  while(str1[i] != '\0') {
    str2[i] = str1[i];
    i++;
  }

  str2[i] = '\0';
}

// 文字数カウント関数
int strLen(char *str) {
  int i=0;

  while(str[i]!='\0') i++;

  return i;
}
