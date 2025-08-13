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
void infix_to_postfix(char str[20],char nstr[20]);
int precedence(char c);
int main(){
	char str[20];
	char nstr[20];
	int i=0;
	printf("Enter the infix expression ");
	scanf("%s",str);
	//printf("%c",str[0]);
	infix_to_postfix(str,nstr);
	printf("The postfix expression is ");
	for(i =0;nstr[i]!='\0';i++){
		printf("%c",nstr[i]);
		}
	
}

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

int precedence(char c){
	if(c=='^'){
		return 3;
	}else if(c=='/'|| c=='*' || c=='%'){
		return 2;
	}else if(c=='+'|| c=='-'){
		return 1;
	}else if(c=='('){
		return 0;
	}
	return -1;
}

void infix_to_postfix(char str[20], char nstr[20]){
	int i,j=0;
	char symbol;
	for(i =0;str[i]!='\0';i++){
		//printf("%c",str[i]);
		if(isalnum(str[i])){
			nstr[j]=str[i];
			j++;
		}else{
			symbol=str[i];
			int val = precedence(symbol);
//			printf("%d ",val);
			if(top==-1 || symbol=='('){
				push(symbol);
//				display();
			}else if((precedence(peek()))<val){
				push(symbol);
//				display();
			}else if((precedence(peek()))>=val){
				if(symbol!=')'){
					while((precedence(peek()))>=val){
					int e = pop();
					nstr[j]=e;
					j++;	
				}
				push(symbol);
				}else{
					while(peek()!='('){
						int f = pop();
						nstr[j]=f;
						j++;
					}
					pop();
				}
			}
			
		}
		if(str[i+1]=='\0'){
			while(peek()!=-4){
				int h =pop();
				nstr[j]=h;
				j++;
			}
		}
		
		
	}
	nstr[j]='\0';
	
//	return nstr;
//	for(i =0;nstr[i]!='\0';i++){
//		printf("%c",nstr[i]);
//		}
	}


