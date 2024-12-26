#include <stdio.h>
#include <string.h>

int stack[30],top=-1;

void push(int value){
    stack[++top]=value;
}

int pop(){
    return stack[top--];
}

int main(){
    char postfix[30],sym;
    int op1,op2,i;
    
    printf("enter postfix expression : ");
    scanf(" %s",postfix);
    
    for(i=0;i<strlen(postfix);i++){
        sym=postfix[i];
        switch(sym){
            case '+':op2=pop();
                    op1=pop();
                    push(op1+op2);break;
            case '-':op2=pop();
                    op1=pop();
                    push(op1-op2);break;
            case '*':op2=pop();
                    op1=pop();
                    push(op1*op2);break;
            case '/':op2=pop();
                    op1=pop();
                    push(op1/op2);break;
            default: push(sym-'0');
                    break;
        }
    }
    printf("the result is %d",pop());
}
