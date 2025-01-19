#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the stack
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *top = NULL; // Top of the stack
Node *create(){
    Node *newnode;
    newnode=(Node*)malloc(sizeof(Node));
    if(!newnode){
        printf("stack overflow, memory allocation failed");
    }else{
         printf("enter the valuw to inset: ");
         scanf("%d",&newnode->data);
    
    newnode->next=NULL;
    }
    return newnode;
}

// Function to push an element onto the stack
void push() {
    Node *newnode=create();
    newNode->next = top;
    top = newNode;
    
}

// Function to pop an element from the stack
int pop() {
    if(top==NULL){
        printf("stack underflow");
        return -1;
    }
    Node *temp = top;
    int poppedValue = temp->data;
    top = top->next;
    free(temp);
    printf("%d popped from the stack.\n", poppedValue);
    return poppedValue;
}



// Function to display the stack
void display() {
    if (top==NULL) {
        printf("The stack is empty.\n");
        return;
    }
    Node *temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
               
                push();
                break;
            case 2:
                pop();
                break;
            
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
