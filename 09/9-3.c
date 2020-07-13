#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
  int val;
  struct cell *next;
} CELL;

void printList(CELL *top);
void insertList(CELL *top, CELL *tmp1);
void freeList(CELL *top);

int main(void) {
  CELL *top;
  CELL *bottom, *tmp;
  int input;

  top = malloc(sizeof(CELL));
  bottom = malloc(sizeof(CELL));
  top->val = 0;
  bottom->val = 100;
  top->next = bottom;
  bottom->next = NULL;

  while(1) {
    printf("追加するデータを入力してください(1-99): ");
    scanf("%d", &input);

    if(input<1 || 99<input) break;

    tmp = malloc(sizeof(CELL));
    tmp->val = input;

    insertList(top, tmp);

    printList(top);
  }

  freeList(top);

  return 0;
}

void printList(CELL *top) {
  CELL *list = top;

  printf("-----------------------\n");

  while (list != NULL) {
    printf("%d\n", list->val);
    list = list->next;
  }

  printf("-----------------------\n");
}


void insertList(CELL *top, CELL *tmp) {
  CELL *pt = top;

  while(pt->val!=100) {
    if(pt->next->val > tmp->val) {
      tmp->next = pt->next;
      pt->next = tmp;
      break;
    }
    pt = pt->next;
  }
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
