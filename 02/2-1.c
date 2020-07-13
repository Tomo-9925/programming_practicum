#include <stdio.h>

typedef struct {
  int student_id;
  char name[21];
  char gender;
  int point;
} STUDENT;

int main() {
  FILE *fp;
  STUDENT new;

  printf("追加する成績情報を入力して下さい．\n");
  printf("学籍コード: ");
  scanf("%d", &new.student_id);
  printf("名前: ");
  scanf("%s", new.name);
  printf("性別: ");
  scanf(" %c", &new.gender);
  printf("評価点: ");
  scanf("%d", &new.point);
  
  fp = fopen("02student.txt", "a");
  fprintf(fp, "%d %s %c %d\n", new.student_id, new.name, new.gender, new.point);
  printf("ファイルに書き込みました．\n");
  fclose(fp);

  return 0;
}
