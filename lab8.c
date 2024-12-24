#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

struct dll{
    int ssn;
    char name[max];
    int salary;
    struct dll *next,*prev;
};

typedef struct dll node;
node* head=NULL;

node *create(){
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    if(!newnode){
        printf("allocation failed\n");
        exit(0);
    }else{
        printf("enter ssn name and salary\n");
        scanf("%d %s %d",&newnode->ssn,newnode->name,&newnode->salary);
    
        newnode->next=NULL;
        newnode->prev=NULL;
    }
    return newnode;
}

void in_front(){
    node* newnode;
    newnode=create();
    if(head==NULL){
        head=newnode;
    }else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}

void in_rear(){
    node* newnode;
    newnode=create();
    if(head==NULL){
        head=newnode;
    }else{
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    newnode->prev=temp;
        
    }
}

void del_front(){
    node* temp=head;
    if(head==NULL){
        printf("dll empty\n");
    
    }
    else if(head->next==NULL){
        head=NULL;
        free(temp);
        
    }else{
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
}

void del_rear(){
    node* temp=head;
    if(head==NULL){
        printf("dll empty\n");
        
    }
    else if(head->next==NULL){
        head=NULL;
        free(temp);
    }else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        (temp->prev)->next=NULL;
        free(temp);
    }
}

void display(){
    int c=0;
    node* temp=head;
    if(head==NULL){
        printf("dll is empty\n");
        return;
    }else{
        printf("dll elements are\n");
    while(temp!=NULL){
        printf("%d \t %s \t %d \n",temp->ssn,temp->name,temp->salary);
        temp=temp->next;
        c++;
    }
    printf("\n no of elements in dll are: %d",c);
    }
}

int main(){
    int n,ch,i;
    while(1){
        printf("1.create dll\n2.insert front\n3.insert end\n4.delete front\n5.delete end\n6.display\n7.exit\n");
        printf("enter chocie: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("enter the no of elements: ");
                    scanf("%d",&n);
                    for(i=0;i<n;i++){
                        in_rear();
                        
                    } break;
            case 2:in_front(); break;
            case 3:in_rear(); break;
            case 4:del_front(); break;
            case 5:del_rear(); break;
            case 6:display(); break;
            case 7:return 0;
            default: printf("enter valid input \n");
        }
    }
    return 0;
}
