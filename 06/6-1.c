#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int len, i;
  char *a;

  printf("Please write string length.\n");
  scanf("%d", &len);

  // a = (char *)malloc(sizeof(char)*len+1);
  a = (char *)malloc(sizeof(char)*len);
  if(a==NULL) return -1;

  printf("Please write string.\n");
  scanf("%s", a);

  // printf("%s", a);
  printf("The string you wrote is ");
  for(i=0; i<len; i++) printf("%c", *(a+i));
  printf(".\n");

  free(a);

  return 0;
}
