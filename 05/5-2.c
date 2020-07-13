#include <stdio.h>

int fib_memo[1000] = {0};

int fib(int n) {
    if(n==0)return 0;
    if(n==1)return 1;
    if(fib_memo[n] != 0) {
        return fib_memo[n];
    }
    return fib_memo[n] = fib(n-1)+fib(n-2);
}

int main(void) {
  int num;
  int i=0;

  printf("n番目の数字を入力してください: ");
  scanf("%d", &num);

  for(i=0; i<num; i++) printf("%d\n", fib(i));

  return 0;
}
