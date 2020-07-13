#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
  int val;
  struct cell *next;
} CELL;

void printList(CELL *top);
void freeList(CELL *top);

int main(void) {
  CELL *top = NULL;
  CELL *bottom, *tmp;
  int input;

  while(1) {
    printf("追加するデータを入力してください(0:終了): ");
    scanf("%d", &input);

    if(input==0) break;

    tmp = malloc(sizeof(CELL));
    tmp->val = input;

    if(top==NULL) {
      top = tmp;
    } else {
      bottom->next = tmp;
    }

    bottom = tmp;

    printList(top);
  }

  freeList(top);

  return 0;
}

void printList(CELL *top) {
  CELL *list = top;

  printf("現在のリスト内容\n");
  printf("-----------------------\n");

  while (list != NULL) {
    printf("%d\n", list->val);
    list = list->next;
  }

  printf("-----------------------\n");
}

void freeList(CELL *top) {
  CELL *tmp;
  tmp = top;
  while(tmp != NULL) {
    top = top->next;
    free(tmp);
    tmp = top;
  }
}
