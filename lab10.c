#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int data;
    struct tree *left,*right;
}node;
node *root=NULL;

node* create(){
    node* nn;
    int data;
    nn=(node*)malloc(sizeof(node));
    printf("enter the data: ");
    scanf("%d",&data);
    nn->data=data;
    nn->left=nn->right=NULL;
    return nn;


}

void insert(){
    node* nn,*temp=root,*prev=NULL;
    nn=create();
    if(root==NULL){
        root=nn;
    }else{
        while(temp!=NULL){
            prev=temp;
            if(nn->data<temp->data)
                temp=temp->left;
            else
                temp=temp->right;

        }
        if(nn->data<prev->data)
            prev->left=nn;
        else
            prev->right=nn;
    }
}

void preorder(node* root){
    if(root!=NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

void postorder(node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d \t",root->data);

    }
}

int search(int key){
    node* temp=root;
    while(temp!=NULL){
        if(key==temp->data){
            return 1;
        }else if(key<temp->data){
            temp=temp->left;
        }else
            temp=temp->right;
    }
    return 0;
}

int main(){
    int ch,i,n,key;
    while(1){
        printf("\nmenu\n");
        printf("1.insert\n2.preorder\n3.inorder\n4.postorder\n5.search key\n6.exit\n");
        printf("enter chocie: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("enter no of terms: ");
                scanf("%d",&n);
                for(i=0;i<n;i++){
                    insert();
                }break;
            case 2: printf("preorder: ");
                preorder(root);break;
            case 3: printf("inorder: ");
                inorder(root);break;

            case 4: printf("postorder: ");
                postorder(root);break;
            case 5: printf("enter key to be searched: ");
                scanf("%d",&key);
                if(search(key)){
                    printf("search successful\n");
                }       else
                    printf("search unsuccessful\n");
                break;
            case 6:return 0;
            default: printf("enter valid choice\n");
        }
    }
    return 0;
}
