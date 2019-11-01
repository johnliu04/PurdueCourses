#include <stdlib.h>
#include "main.h"

Stack * INITIAL(){
  TreeNode **arr = malloc(sizeof(TreeNode) * 1);
  Stack * s = malloc(sizeof(Stack));
  s->arr = arr;
  s->top = -1;
  s->capacity = 1;
  return s;
}

int FULL(Stack * s){
  return s->top == s->capacity - 1;
}

int EMPTY(Stack * s){
  return s->top == -1;
}

TreeNode* TOP(Stack* s){
  return s->arr[s->top];
}

void PUSH(Stack* s, TreeNode* tn){
  if(FULL(s))
  {
    s->capacity *= 2;
    s->arr = realloc(s->arr, sizeof(TreeNode) * s->capacity);
  }
  s->arr[++s->top] = tn;
  return;
}

TreeNode* POP(Stack* s){
  return s->arr[s->top--]; 
}

void FREE(Stack* s){
  free(s->arr);
  free(s);
}