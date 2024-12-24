#include <stdio.h>
#include<stdlib.h>
#define max 30

struct sll{
    char usn[max];
    char name[max];
    int sem;
    struct sll *next;
};

typedef struct sll node;
node *head=NULL;

node *create(){
    node *newnode=(node*)malloc(sizeof(node));
    if(!newnode){

        printf("mem alloc failed\n");
        exit(1);
    }else{
        printf("enter usn , name and sem\n");
        scanf("%s %s %d",newnode->usn,newnode->name,&newnode->sem);

        newnode->next=NULL;
    }
    return newnode;

}

void in_front(){

    node *newnode;
    newnode=create();
    newnode->next=head;
    head=newnode;
}

void in_rear(){
    node *newnode;
    newnode=create();
    if(head==NULL){
        head=newnode;
    }
    node *temp=head;
    while(temp->next!=NULL){

        temp=temp->next;
    }
    temp->next=newnode;

}

void del_front(){
    if(head==NULL){
        printf("sll empty\n");
    }
    node* temp;
    temp=head;
    head=head->next;
    free(temp);
}

void del_rear(){
    node  *temp=head,*prev;
    if(head==NULL){
        printf("sll empty\n");
        return;
    }
    if(head->next==NULL){
        free(head);
        head=NULL;
        return;
    }
    else{
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;

    }
    free(temp);
}

void display(){
    int c=0;
    if(head==NULL){
        printf("sll empty\n");
    }else{
        node *temp=head;
        printf("sll contents are \n");
        while(temp!=NULL){
            printf("%s\t %s\t %d\n",temp->usn,temp->name,temp->sem);

            c++;
            temp=temp->next;
        }
        printf("no of nodes are: %d",c);
    }

}

int main(){
    int n,choice,i;
    while(1){
        printf("1.insert front\n2.insert rear\n3.delete front\n4.delete rear\n5.display\n6.exit\n");
        printf("enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("\nenter the number of elements: ");
                scanf("%d",&n);
                for(i=0;i<n;i++){
                    in_front();
                }
                break;
            case 2:in_rear();
                break;
            case 3:del_front();
                break;
            case 4:del_rear();
                break;
            case 5: display();
                break;
            case 6:return 0;
            default:printf("enter valid choice");
        }
    }
}
