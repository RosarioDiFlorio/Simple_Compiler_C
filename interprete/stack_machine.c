#include <stdio.h>
#include <stdlib.h>




void swap(struct stackNode *top){
		struct stackNode *tmp;
		struct stackNode *head;
		
		head = top->next; //s
		printf("swap: %s\n",head->data);
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
			//printf("tolgo l'operatore\n");
			top = pop(top,toPop); //tolgo l'operatore
			//printf("%s\n",toPop);
			//printf("tolgo il secondo operando\n");
			top = pop(top,toPop); // secondo operando
			//printf("%s\n",toPop);
			int b = atoi(toPop);
			//printf("tolgo il primo operando\n");			
			top = pop(top,toPop); // primo operando
			//printf("%s\n",toPop);
			int a = atoi(toPop);
			//printf("sommo: %d + %d\n",a,b);
			int ris = a + b;
			//printf("ris: %d\n", ris);
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

void process(char *buff,struct stackNode *top){
	    printf("stato della stack machine:\n");
		printf("###########################\n");
		printStack(top);
		printf("###########################\n");
		if(strcmp(buff,"e")== 0){
			printf("\nevaluate\n\n");
			evaluate(top);
					
		}else{
			printf("\ninserisco\n\n");		
			top = push(top,buff);
		}
			
	

}


			
