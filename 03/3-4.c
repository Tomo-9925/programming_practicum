#include <stdio.h>

typedef struct {
  int student_id;
  char name[21];
  char gender;
  int point;
} STUDENT;

int main() {
  FILE *fp;
  int i = 0;
  int j = 0;
  STUDENT st[20];
  STUDENT *pt = st;

  /* ファイルオープン処理 */
  fp = fopen("../02/02student.txt","r");

  /* 構造体配列の各メンバに対し、値の設定(ポインタ変数ptを利用) */
  while(fscanf(fp, "%d %s %c %d", &(pt+i)->student_id, (pt+i)->name, &(pt+i)->gender, &(pt+i)->point) != EOF) {
    i++;
  }

  /* ファイルクローズ処理 */
  fclose(fp);

  /* ポインタ変数ptを利用し、構造体配列の各メンバを参照し出力 */
  while(j<i) {
    printf("%d\t%s\t%c\t%d\n", (pt+j)->student_id, (pt+j)->name, (pt+j)->gender, (pt+j)->point);
    j++;
  }

  return 0;
}