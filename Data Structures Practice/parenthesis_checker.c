#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define max 20
char stack[max];

int top=-1;
void push(char n);
char pop();
char peek();
void display();
int paranthesischeck(char str[20]);
int precedence(char c);

void push(char n){
	if(top==max-1){
		printf("Stack overflow \n");
	}
	else{
		top=top+1;
		stack[top]=n;
		//printf("element has been inserted \n");
	}
}

void display(){
	if(top==-1){
		printf("stack is empty \n");
	}else{
		int i;
		printf("Your stack is \n");
		for(i =top;i>=0;i--){
			printf("|%c|\n",stack[i]);
		}
	}
}

char pop(){
	if(top==-1){
//		printf("nothing to pop\nStack underflow \n");
		return -1;
	}else{
		char g;
		g=stack[top];
		top=top-1;
		return g;
	}
}

char peek(){
	if(top==-1){
		//printf("Stack is empty ");
		return -4;
	}else{
		return stack[top];
	}
}

int paranthesischeck(char str[20]){
	int i,j=0;
	char symbol;
	for(i=0;str[i]!='\0';i++){
		symbol=str[i];
		if(symbol=='('|| symbol=='{'|| symbol=='['){
			push(symbol);
		}
         
		if(symbol==')'|| symbol=='}'|| symbol==']'){
			if((peek()=='('&& symbol==')') || (peek()=='{'&& symbol=='}') || (peek()=='['&& symbol==']')){
				pop();
			}else if(peek()==-4){
				return -1;
			}else{
				return -1;
			}
		}
	}
//	display();
	if(peek()==-4){    
		return 1;
	}else{
		return -1;
	}
}

int main(){
	char str[20];
	printf("Enter the expression ");
	scanf("%s",str);
	int a = paranthesischeck(str);
//	printf("%d",a);
	if(a==1){
		printf("The expression is valid ");
	}else{
		printf("The expression is not valid ");
	}
}
