#include <stdio.h>
#include <stdlib.h>


struct stackNode
{   
  char* data;
  struct stackNode *next;
   
};

void printStack(struct stackNode *top){
	struct stackNode *p;
	p = top->next;	
	while(p != NULL){
		printf("%s\n",p->data);
		p = p->next;	
	}
}


void swap(struct stackNode *a, struct stackNode *b){
				

}

int main()
{	
	int len = 0;
	struct stackNode *top = malloc(sizeof(struct stackNode));
	struct stackNode *newNode = NULL;	
	top->data = NULL;
	top->next = NULL;
	int flag = 1;
	char buff[128];
	while(flag){
		scanf("%s", buff);
		//printf("%s\n",buff);
		if(strcmp(buff,"d")== 0){
			//printf("print\n");		
			printStack(top);
		}else if(strcmp(buff,"e")== 0){
			//printf("evaluate\n");		
		}else if(strcmp(buff,"x")== 0){
			//printf("exit\n");		
		}else{
			//printf("inserisco\n");		
			newNode = malloc(sizeof(struct stackNode));
			newNode->data = (char*)malloc(sizeof(buff) + 1);
			strcpy(newNode->data,buff);
			if(top->next == NULL)
				newNode->next = NULL;			
			else
				newNode->next = top->next;
			top->next = newNode;
			newNode = NULL;
		}
	}		


}


