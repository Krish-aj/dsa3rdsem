#include <stdio.h>
#include <stdlib.h>
#define max 3

void insert(char[],int *,int*);
void delete(char[],int*,int*);
void display(char[],int,int);

int main(){
    char q[max];
    int f=0,r=-1,cnt=0,ch;

    while(1){
        printf("1.insert\n2.delete\n3.display\n4.exit\n");
        printf("enter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                insert(q,&r,&cnt);
                break;
            case 2:
                delete(q,&f,&cnt);
                break;
            case 3:
                display(q,f,cnt);
                break;
            case 4:
                return 0;
            default:
                printf("enter valid choice\n");
        }
    }
    return 0;
}

void insert(char q[],int *r,int *cnt){
    char value;
    if((*cnt)==max){
        printf("queue overflow\n");
    }
    *r=(*r+1)%max;
    printf("enter the value to insert: ");
    scanf(" %c",&value);
    q[*r]=value;
    (*cnt)++;

}

void delete(char q[],int* f,int* cnt){
if(*cnt==0){
printf("queue empty\n");
return;
}else{
printf("element deleted from queue is %c\n",q[*f]);
}
*f=(*f+1)%max;
(*cnt)--;
}
void display(char q[],int f, int cnt){
    int i,j;
    printf("queue elements are\n");
    for( i=f,j=0;j<cnt;j++){
        printf("%c \n",q[i]);
        i=(i+1)%max;
    }
}
