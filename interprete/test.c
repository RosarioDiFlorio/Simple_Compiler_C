#include <stdio.h>
#include "stack.h"

int main()
{	
	int len = 0;
	struct stackNode *top = malloc(sizeof(struct stackNode));
	
	top->data = NULL;
	top->next = NULL;
	
	char buff[128];
	char toPop[128];
	for(;;){
		
		scanf("%s", buff);	
		if(strcmp(buff,"d")== 0){
			//printf("print\n");		
			printStack(top);
		}else if(strcmp(buff,"p")== 0){
			top = pop(top,toPop);
			printf("pop of %s\n",toPop);		
		
		}else if(strcmp(buff,"f")== 0){
			top = freeStack(top);
			printf("stack free\n");		
		
		}else if(strcmp(buff,"l")== 0){
			
			printf("len stack: %d\n",lenStack(top));		
		
		}else{
			top = push(top,buff);
			printf("inserito\n");	
		}
	}
		
		
	printf("bye\n");
	exit(0);
}
