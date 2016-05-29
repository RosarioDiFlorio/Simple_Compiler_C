/* in questo test non viene chiuso il commento */
struct stackNode
{   
  char* data;
  struct stackNode *next;
   
};
/*
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

/* 
//####test####
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
		
		}else{
			top = push(top,buff);
			printf("inserito\n");	
		}
	}
		
		
	printf("bye\n");
	exit(0);
}
*/
