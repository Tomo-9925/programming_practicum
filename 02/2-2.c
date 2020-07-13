#include <stdio.h>

typedef struct {
  int student_id;
  char name[21];
  char gender;
  int point;
} STUDENT;

int main() {
  int i = 0;
  int j;
  int k;
  FILE *fp;
  int tmp;
  STUDENT array[20];

  fp = fopen("02student.txt","r");

  //read information
  while(fscanf(fp, "%d%s %c%d", &array[i].student_id, array[i].name, &array[i].gender, &array[i].point) != EOF) {
    i++;
  }

  fclose(fp);

  //scan student_id
  printf("学籍コード: ");
  scanf("%d", &tmp);

  //search studen_id
  for(j=0;j<i;j++) {
    if (tmp == array[j].student_id) {
      k = j;
    }
  }

  //print student information
  printf("学籍コード: %d\n", array[k].student_id);
  printf("名前: %s\n", array[k].name);
  printf("性別: %c\n", array[k].gender);
  printf("評価点: %d\n", array[k].point);

  return 0;
}
