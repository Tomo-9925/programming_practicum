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

  //ファイルを読み込む
  fp = fopen("02student.txt","r");
  while(fscanf(fp, "%d %s %c %d", &array[i].student_id, array[i].name, &array[i].gender, &array[i].point) != EOF) {
    i++;
  }
  fclose(fp);

  //学籍番号を入力
  printf("削除する成績情報を入力してください．\n");
  printf("学籍コード: ");
  scanf("%d", &tmp);

  //学籍コードを検索
  for(j=0;j<i;j++) {
    if (tmp == array[j].student_id) {
      k = j;
      break;
    }
  }

  //02student.txtに書き込む
  fp = fopen("02student.txt","w");
  for (j=0; j<i; j++) {
    if (j!=k) {
      fprintf(fp, "%d %s %c %d\n", array[j].student_id, array[j].name, array[j].gender, array[j].point);
    }
  }
  fclose(fp);

  return 0;
}
