#include <stdio.h>
#include <stdlib.h>


void printStackM(struct stackNode *top){
	struct stackNode *p;
	p = top->next;	
	while(p != NULL){
		printf("%s\n",p->data);
		p = p->next;	
	}
}


void swap(struct stackNode *top){
		struct stackNode *tmp;
		struct stackNode *head;
		
		head = top->next; //s
		top->next = top->next->next;
		tmp = top->next->next;
		top->next->next = tmp->next;
		tmp->next = head->next;
		top->next = tmp;
		
}

void evaluate(struct stackNode *top){
	struct stackNode *p = top->next;
		//printf("%s\n",p->data);
		if(strcmp(p->data,"s")==0){
			swap(top);
		}else if(strcmp(p->data,"+")==0){
			struct stackNode *tmp = p->next;
			int a = atoi(tmp->data);
			tmp = tmp->next;
			int b = atoi(tmp->data);
			int ris = a + b;
			sprintf(tmp->data, "%d", ris);
			p = tmp;
				 top->next = p;
		}else if(strcmp(p->data,"-") == 0){
			struct stackNode *tmp = p->next;
			int a = atoi(tmp->data);
			tmp = tmp->next;
			int b = atoi(tmp->data);
			int ris = a - b;
			sprintf(tmp->data, "%d", ris);
			p = tmp;
			top->next = p;

		}else if(strcmp(p->data,"*") == 0){
			struct stackNode *tmp = p->next;
			int a = atoi(tmp->data);
			tmp = tmp->next;
			int b = atoi(tmp->data);
			int ris = a * b;
			sprintf(tmp->data, "%d", ris);
			p = tmp;
			top->next = p;
		
		}else if(strcmp(p->data,"/") == 0){
			struct stackNode *tmp = p->next;
			int a = atoi(tmp->data);
			tmp = tmp->next;
			int b = atoi(tmp->data);
			int ris = a / b;
			sprintf(tmp->data, "%d", ris);
			p = tmp;
			top->next = p;		
		}	
		
			
	
}

void process(char *buff,struct stackNode *top){
	
		struct stackNode *newNode = NULL;
		//printf("%s\n",buff);
		if(strcmp(buff,"e")== 0){
			evaluate(top);
			//printf("evaluate\n");		
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

/*

//######test####
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
	printf("bye\n");
	exit(0);
}
*/

