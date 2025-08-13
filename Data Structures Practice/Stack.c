#include <stdio.h>
#include <conio.h>
#define max 6
int stack[max];
int top=-1;
void push();
int pop();
int peek();
void display();
int main(){
	
	while(1){
		int choice;
		int want;
		printf("What do you want to do ? \n 1 for push \n 2 for pop \n 3 to display \n 4 to peek \n");
		scanf("%d",&choice);
		switch (choice){
		
			case 1:{
				push();
				break;
			}
			case 2:{
				int val = pop();
				if(val==-1){
					
				}else{
					printf("Poped value is %d \n",val);
				}
				
				break;
			}
			case 3:{
				display();
				break;
			}
			case 4:{
				int val=peek();
				if(val==-1){
					printf("no elements ");
				}else{
					printf("the top element is ",val);
				}
				break;
			}
			default:{
				printf("invalid choice \n");
				break;
			}
		}
			printf("Do you want to continue \n 1 to yes \n 2 to no \n ");
			scanf("%d",&want);
			if(want==1){
				
			}else{
				break;
			}
	}
}

void push(){
	if(top==max-1){
		printf("Stack overflow \n");
	}
	else{
		top=top+1;
		int n;
		printf("enter the element you want to insert ");
		scanf("%d",&n);
		stack[top]=n;
		printf("element has been inserted \n");
	}
}

void display(){
	if(top==-1){
		printf("stack is empty \n");
	}else{
		int i;
		printf("Your stack is \n");
		for(i =top;i>=0;i--){
			printf("|%d|\n",stack[i]);
		}
	}
}

int pop(){
	if(top==-1){
		printf("nothing to pop\nStack underflow \n");
		return -1;
	}else{
		int g;
		g=stack[top];
		top=top-1;
		return g;
	}
}

int peek(){
	if(top==-1){
		printf("Stack is empty ");
		return -1;
	}else{
		return stack[top];
	}
}

