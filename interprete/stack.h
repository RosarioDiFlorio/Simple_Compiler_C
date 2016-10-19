#include "stack.c"

char * getTop(struct stackNode *top);

struct stackNode* push(struct stackNode *top,char *buff);

struct stackNode* pop(struct stackNode *top,char *buff);

void printStack(struct stackNode *top);

int isEmpty(struct stackNode *top);

struct stackNode * freeStack(struct stackNode *top);

int lenStack(struct stackNode *top);
