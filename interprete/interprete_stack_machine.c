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
	int invio = 0;
	int leftOp = 0;
        
        //STACKs DI SERVIZIO
        struct stackNode *top = malloc(sizeof(struct stackNode));
	top->data = NULL;
	top->next = NULL;
        
	struct stackNode *finale = malloc(sizeof(struct stackNode));
	finale->data = NULL;
	finale->next = NULL;
        
	struct stackNode *pozzo = malloc(sizeof(struct stackNode));
	pozzo->data = NULL;
	pozzo->next = NULL;
        
	//la stringa andrà in una struct per essere processata
	struct node *head = malloc(sizeof(struct node));
	head->data = NULL;
	head->next = NULL;
	struct node *tail = malloc(sizeof(struct node));
	tail->data = NULL;
	tail->next = NULL;

	
	printf("benvenuto:\n");
	printf("inserisci qui la tua espressione lasciando lo spazio per ogni elemento dell'espressione\n");
	printf("(Es: 1 + 3 - 4)\n");
	printf("NB: non sono supportate le parentesi\n");
	printf("premi 2 volte \"invio\" per uscire\n");
	
for(;;){
	printf("inserisci una espressione\n");
	printf(">");
	gets(buff);
        
        //LOGICA DI USCITA DALL'INTERPRETE
	if(strcmp(buff,"")==0){
		invio++;
		if(invio == 2){
			printf("bye\n");
			exit(0);
		}
	}else{
			invio = 0;
				//printf("%s\n",buff);

				  /* get the first token */
			   token = strtok(buff, s);
			   
                           //costruisco la lista linkata di nodi contenete la mia espressone
			   /* walk through other tokens */
			   while( token != NULL ) 
			   {
				  //printf( "%s\n", token );
				  //prendo i token e li inserisco in una lista a puntatori in cui mantengo la tail
				  struct node * tmp = malloc(sizeof(struct node));
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
						leftOp = 1;
						pozzo = push(pozzo, str);
						
					}else{
						pozzo = push(pozzo, str);
						if(leftOp){
							leftOp = 0;
							pozzo = push(pozzo, "s");
							pozzo = push(pozzo, "e");
							pozzo = push(pozzo, "e");
						}
					}
				curr = curr->next;
				}

			
			//uso uno stack per capovolgere la stringa
			while(!isEmpty(pozzo)){
				pozzo = pop(pozzo,toPop);
				finale = push(finale,toPop);
	
			}

			printf("stringa formattata per la macchina a stack\n");
			printStack(finale);

			while(!isEmpty(finale)){

				finale = pop(finale,toPop);
				process(toPop,top);
	
			}

			printf("\nrisultato:\n");
			printStack(top);
			printf("\n\nsvuoto lo stack\n");
			
			
		}
			
			freeStack(finale);
			freeStack(pozzo);
			freeStack(top);

			
			
			head->next = NULL;
			tail->next = NULL;
			
			
	}
	return 0;
}
