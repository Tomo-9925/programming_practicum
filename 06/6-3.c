#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *name[5];
  int i;
  FILE *fp;

  fp = fopen("05write_person.txt","w");

  for(i=0; i<5; i++) {
    printf("Please write person%d name: ", i+1);
    name[i] = malloc(sizeof(char)*20);
    scanf("%s", name[i]);
  }

  for(i=0; i<5; i++) {
    fprintf(fp, "%s\n", name[i]);
  }

  fclose(fp);

  for(i=0; i<5; i++) free(name[i]);

  printf("\nDone.\n");

  return 0;
}
