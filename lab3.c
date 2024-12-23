#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define max 100

typedef struct stack{
    int data[max];
    int top;
}stack;

void initialize(stack *stack){
    stack->top=-1;
}

void push(stack *stack,int value){
    if(stack->top==max-1){
        printf("stack overflow\n");
    }
    else{
        stack->data[++stack->top]=value;
        printf("pushed %d onto the stack\n",value);
    }
}

int pop(stack *stack){
    if(stack->top==-1){
        printf("stack underflow\n");
    }
    else
        return stack->data[stack->top--];
}

bool palindrome(const char *str){
    struct stack stack;
    initialize(&stack);
    int i=0;
    while (str[i] !='\0'){
        push(&stack,str[i]);
        i++;
    }
    i=0;
    while(str[i]!='\0'){
        if(str[i] !=pop(&stack)){
        return false;
    }
    i++;
    }
    return true;
}

void display(stack *stack){
    int i;
    for(i=stack->top;i>=0;i--){
        printf("the stack data are :%d\n",stack->data[i]);
    }
}

int main(){
    struct stack stack;
    initialize(&stack);
    int choice,element;
    char str[max];
    while(true){
    printf("\n--------menu-------\n");
    printf("1.push\n 2.pop\n 3.palindrome\n 4.display\n 5.exit\n");
    printf("enter your choice: ");
    scanf("%d",&choice);
    
        switch(choice){
            case 1: printf("enter the element to push onto stack: ");
                    scanf("%d",&element);
                    push(&stack,element);
                    break;
            case 2: element=pop(&stack);
                    printf("the element %d is popped out of stack",element);
                    break;
            case 3: printf("enter the sting to check : ");
                    scanf(" %[^\n]",str);
                    if(palindrome(str)){
                        printf("the string is a palindrome\n");
                    }else{
                        printf("not a plaindrome\n");
                    }
                    break;
            case 4: display(&stack);
                    break;
            case 5: return 0;
            default: printf("enter a valid choice\n");
        }
    }
    return 0;
}
