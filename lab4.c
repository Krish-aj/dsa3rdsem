#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

char stack[100];
int top=-1;

void push(char oper){
    stack[++top]=oper;
}

char pop(){
   return stack[top--];
}

int preced(char oper){
    if(oper=='%'||oper=='^') return(4);
    if(oper=='*'||oper=='/') return(3);
    if(oper=='+'||oper=='-') return(2);
    if(oper=='('||oper=='#') return(1);
}

int main(){
    char infix[100],postfix[100];
    int i,j=0;
    printf("enter infix expession: ");
    scanf(" %s",infix);
    
    push('#');
    for(i=0;infix[i]!='\0';i++){
        if(infix[i]=='('){
            push('(');
        }
        else if(isalnum(infix[i])){
            postfix[j++]=infix[i];
        }
        else if(infix[i]==')'){
            while(stack[top]!='('){
                postfix[j++]=pop();
            }
            pop();
        }
        else{
            while(preced(stack[top])>=preced(infix[i])){
                postfix[j++]=pop();
            }
            push(infix[i]);
        }
        
    }
    while(stack[top]!='#'){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("infix: %s\n",infix);
    printf("postfix: %s",postfix);
    getchar();
}
