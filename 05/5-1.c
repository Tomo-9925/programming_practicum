#include <stdio.h>

void sort(int *a_pt, int tmp1, int n);

int main(void) {
  int array[10];
  int tmp;
  int i, j;

  for(i=0; i<10; i++){
    printf("%d番目の数字を入力してください: ", i+1);
    scanf("%d", &tmp);
    if(tmp!=0) sort(array, tmp, i);
    for(j=0; j<=i; j++) {
      if (tmp==0 && j==i) break;
      printf("%d ", array[j]);
    }
    printf("\n");
    if(tmp==0) break;
  }

  return 0;
}

void sort(int *a_pt, int tmp1, int n) {
  int tmp2;
  int i, j;
  if(n==0) {
    *a_pt = tmp1;
  } else if (tmp1) {
    for(i=0; i<=n; i++) if(*(a_pt+i)>tmp1) { //挿入するべき場所
      tmp2 = *(a_pt+i);
      *(a_pt+i) = tmp1;
      for(j=i+1; j<n+1; j++) {
        tmp1 = *(a_pt+j);
        *(a_pt+j) = tmp2;
        tmp2 = tmp1;
      }
      break;
    }
  }
}
