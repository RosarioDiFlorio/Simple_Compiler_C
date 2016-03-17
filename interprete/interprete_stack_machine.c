#include <stdio.h>
#include "stack.h"
#include <string.h>
#include "stack_machine.h"

struct node{
	char*data;
	struct node* next;
};



int main(){
	char *token;
	char buff[128];
	const char s[2] = " ";
	
	struct stackNode *top = malloc(sizeof(struct stackNode));
	top->data = NULL;
	top->next = NULL;

	struct stackNode *operandi = malloc(sizeof(struct stackNode));
	operandi->data = NULL;
	operandi->next = NULL;
	struct stackNode *operatori = malloc(sizeof(struct stackNode));
	operatori->data = NULL;
	operatori->next = NULL;
	struct stackNode *pozzo = malloc(sizeof(struct stackNode));
	pozzo->data = NULL;
	pozzo->next = NULL;
	//la stringa andrà in una struct per essere processata
	struct node *head = malloc(sizeof(struct stackNode));
	head->data = NULL;
	head->next = NULL;
	struct node *tail = malloc(sizeof(struct stackNode));
	tail->data = NULL;
	tail->next = NULL;

	
	

	gets(buff);
	//printf("%s\n",buff);

	  /* get the first token */
   token = strtok(buff, s);
   
   /* walk through other tokens */
   while( token != NULL ) 
   {
      //printf( "%s\n", token );
	  //prendo i token e li inserisco in una lista a puntatori in cui mantengo la tail
	  struct node * tmp = malloc(sizeof(struct stackNode));
	  tmp->data = malloc(sizeof(token));
	  tmp->data = token;
	  if(head->next == NULL){
		head->next = tmp;
		tail->next = tmp;
	  }
	  else{
		head->next->next = tmp;
		head->next = tmp;
	  }
	  token = strtok(NULL, s);
   }
 /*
 //stampa di debug  
 struct node *cur = tail->next;
  while(cur != NULL){
	printf("%s\n",cur->data);
	cur = cur->next;
  }*/

	char toPop[128];
  	struct node *curr = tail->next;
	//algoritmo di conversione per la macchina a stack
 	while(curr != NULL){
		char *str = curr->data;
		if(strcmp(str,"+") == 0 || strcmp(str,"-") == 0){
			operatori = push(operatori,str);
		}
		else if(strcmp(str,"/") == 0 || strcmp(str,"*") == 0){
			//operatori con priorità alta
			operatori = push(operatori,str);
			char *c = curr->next->data; //leggo il prossimo carattere
			pozzo = push(pozzo,c);
			curr = curr->next;
			if(!isEmpty(operandi)){
				operandi = pop(operandi,toPop);
				pozzo = push(pozzo,toPop);			
			}
			operatori = pop(operatori,toPop);
			pozzo = push(pozzo,toPop);
			pozzo = push(pozzo,"e");
		}
		else{
			operandi = push(operandi,str);
		}
	curr = curr->next;
	}

/*
printf("######pozzo\n");
printStack(pozzo);
printf("######operatori\n");
printStack(operatori);
printf("######operandi\n");
printStack(operandi);
*/
if(lenStack(operandi) > lenStack(operatori)){
	operandi = pop(operandi,toPop);
	pozzo = push(pozzo,toPop);
}else if(lenStack(operandi) < lenStack(operatori)){
	operatori = pop(operatori,toPop);
	pozzo = push(pozzo,toPop);
	pozzo = push(pozzo,"e");
}

while(!isEmpty(operandi) && !isEmpty(operatori)){
	operandi = pop(operandi,toPop);
	pozzo = push(pozzo,toPop);
	operatori = pop(operatori,toPop);
	pozzo = push(pozzo,toPop);
	pozzo = push(pozzo,"e");
}
/*
printf("######pozzo\n");
printStack(pozzo);
printf("######operatori\n");
printStack(operatori);
printf("######operandi\n");
printStack(operandi);
*/

//riuso uno stack per capovolgere la stringa
while(!isEmpty(pozzo)){
	pozzo = pop(pozzo,toPop);
	operandi = push(operandi,toPop);
	
}

printf("stringa formattata per la macchina a stack\n");
printStack(operandi);

while(!isEmpty(operandi)){

	operandi = pop(operandi,toPop);
	process(toPop,top);
	
}

printf("risultato\n");
printStackM(top);

	return 0;
}
