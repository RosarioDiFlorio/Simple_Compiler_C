#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



void swap(struct stackNode *top){
		struct stackNode *tmp;
		struct stackNode *head;
		
                //swap algorithm
		head = top->next; //s
		top->next = top->next->next;
		tmp = top->next->next;
		top->next->next = tmp->next;
		tmp->next = head->next;
		top->next = tmp;
		
}


void evaluate(struct stackNode *top){
		char *str;
		char toPop[128];
		char buff[128];
		str = getTop(top);
		//printf("top: %s\n",str);
		if(strcmp(str,"s")==0){
			swap(top);
		}else if(strcmp(str,"+")==0){
			
			top = pop(top,toPop); //tolgo l'operatore
			
			top = pop(top,toPop); //tolgo il secondo operando
			
			int b = atoi(toPop);
					
			top = pop(top,toPop); //tolgo il primo operando
			
			int a = atoi(toPop);
			
			int ris = a + b; // sommo
			
			sprintf(buff, "%d", ris);
			top = push(top,buff);
			
		}else if(strcmp(str,"-")==0){
			top = pop(top,toPop);//tolgo l'operatore
			top = pop(top,toPop); // secondo operando
			int b = atoi(toPop);
			top = pop(top,toPop); // primo operando
			int a = atoi(toPop);
			int ris = a - b;
			sprintf(buff, "%d", ris);
			top = push(top,buff);
			
		}			
	
}


//######test####
int main()
{	
	int len = 0;
        
	struct stackNode *top = malloc(sizeof(struct stackNode));
	top->data = NULL;
	top->next = NULL;
	
        int flag = 1;
	char buff[128];
	while(flag){
		printf(">");
		scanf("%s", buff);
		//printf("%s\n",buff);
		if(strcmp(buff,"d")== 0){
			//printf("print\n");		
			printStack(top);
		}else if(strcmp(buff,"e")== 0){
			evaluate(top);
			//printf("evaluate\n");		
		}else if(strcmp(buff,"x")== 0){
			//printf("exit\n");	
			flag = 0;	
		}else{
			//printf("inserisco\n");		
			top = push(top,buff);
		}
	}		
	printf("bye\n");
	exit(0);
}


