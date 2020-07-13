#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int student_id;
  char name[21];
  char gender;
  int point;
} STUDENT;

int main(void) {
  int i;
  FILE *fp;
  STUDENT *st = malloc(sizeof(STUDENT)*10);

  fp = fopen("../02/02student.txt","r");

  for(i=0; i<10; i++) {
    fscanf(fp, "%d%s %c%d", &st[i].student_id, st[i].name, &st[i].gender, &st[i].point);
  }

  for(i=0; i<10; i++) {
    printf("%d\t%s\t%c\t%d\n", (st+i)->student_id, (st+i)->name, (st+i)->gender, (st+i)->point);
  }

  fclose(fp);

  free(st);

  return 0;
}
