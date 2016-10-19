#include <stdio.h>


struct stackNode
{   
  char* data;
  struct stackNode *next;
   
};

char* getTop(struct stackNode *top){
	if(!isEmpty(top))\
		return top->next->data;
	return NULL;
}


struct stackNode* push(struct stackNode *top,char *buff){
		struct stackNode *newNode = NULL;	
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
		return top;
}


struct stackNode* pop(struct stackNode *top,char *buff){
	if(!isEmpty(top)){
		struct stackNode *newNode = NULL;
		newNode = top->next;
		top->next = top->next->next;
		if(buff != NULL)
			strcpy(buff,newNode->data);
			
		free(newNode);
		return top;
	}else{
		strcpy(buff,"stack vuoto\n");
		return top;
	}
}

void printStack(struct stackNode *top){
	if(!isEmpty(top)){
		struct stackNode *p;
		p = top->next;	
		while(p != NULL){
			printf("%s\n",p->data);
			p = p->next;	
		}
	}else{
		printf("stack vuoto\n");
	}
}

int isEmpty(struct stackNode *top){

	if(top->next == NULL)return 1;
	return 0;
}

struct stackNode * freeStack(struct stackNode *top){
	
	while(top->next != NULL){
		top = pop(top,NULL);
	}
	return top;

}


int lenStack(struct stackNode *top){
	int i = 0;
	if(!isEmpty(top)){
		struct stackNode *p;
		p = top->next;	
		while(p != NULL){
			i++;
			p = p->next;	
		}
		return i;
	}else{
		return 0;
	}

}
