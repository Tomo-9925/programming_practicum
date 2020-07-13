#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
  int val;
  struct cell *next;
} CELL;

void printList(CELL *top);

int main(void) {
  CELL *top = NULL;
  CELL *bottom, *tmp;
  int input;

  while(1) {
    printf("データを入力してください: ");
    scanf("%d", &input);

    if(input <= 0) break;

    tmp = malloc(sizeof(CELL));
    tmp->val = input;

    if(top==NULL) {
      top = tmp;
    } else {
      bottom->next = tmp;
    }

    bottom = tmp;
  }

  printList(top);

  tmp = top;
  while(tmp != NULL) {
    top = top->next;
    free(tmp);
    tmp = top;
  }

  return 0;
}

void printList(CELL *top) {
  CELL *list = top;
  while (list != NULL) {
    printf("%d\n", list->val);
    list = list->next;
  }
}
