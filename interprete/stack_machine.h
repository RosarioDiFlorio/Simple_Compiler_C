#include <stdio.h>
#include <stdlib.h>
#include "stack_machine.c"



void printStackM(struct stackNode *top);

void swap(struct stackNode *top);

void evaluate(struct stackNode *top);

void process(char *buff,struct stackNode *top);
