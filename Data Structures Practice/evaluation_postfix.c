#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define max 20
float stack[max];

int top=-1;
void push(float n);
float pop();
float peek();
void display();
float evaluatepostfix(char str[20]);
float operation(char c,float op1,float op2);
//int precedence(char c);

void push(float n){
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
			printf("|%f|\n",stack[i]);
		}
	}
}

float pop(){
	if(top==-1){
//		printf("nothing to pop\nStack underflow \n");
		return -1;
	}else{
		float g;
		g=stack[top];
		top=top-1;
		return g;
	}
}

float peek(){
	if(top==-1){
		//printf("Stack is empty ");
		return (-4.0);
	}else{
		return stack[top];
	}
}

float operation(char c,float op1,float op2){

	if(c=='+'){
		return (op1+op2);
	}
	if(c=='-'){
		return (op1-op2);
	}
	if(c=='*'){
		return (op1*op2);
	}
	if(c=='/'){
		return (op1/op2);
	}
}

float evaluatepostfix(char str[20]){
	//printf("you have called evaluate postfix");
	int i,j=0;
	float op1=0;
	float op2=0;
	char symbol;
	for(i=0;str[i]!='\0';i++){
		if(isdigit(str[i])){
			float n =(float)(str[i]-'0');
			push(n);
		}else{
			op2=pop();
			op1=pop();
			symbol=str[i];
			float val = operation(symbol,op1,op2);
			push(val);
			
		}
	}
	//display();
	if(top==0){
		float ans = pop();
		return ans;
	}else{
		return -1.0;
	}
	//printf("%f ",(op1-op2));
}

int main(){
	char str[20];
	printf("enter the expression ");
	scanf("%s",str);
	float a = evaluatepostfix(str);
	if(a==-1){
		printf("inavlid postfix expression");
	}else{
		printf("The expression evaluates to %f",a);
	}
	
}
