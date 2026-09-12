
#include <stdio.h>
#include<stdlib.h> 
struct node{
    int e;
    struct node* lc;
    struct node* rc;
};
typedef struct node* bt;
bt create(int root){
    bt rootn=(struct node*)malloc(sizeof(struct node));
    rootn->e=root;
    rootn->lc=NULL;
    rootn->rc=NULL;
    return rootn;
}
bt createchild(bt t,int e){
    if(t->lc==NULL){
        t->lc=create(e);
        return t->lc;
    }
    else{
        t->rc=create(e);
        return t->rc;
    }
}
void postordertraversal(bt root){
    if(root!=NULL){
        if(root->lc!=NULL){
            postordertraversal(root->lc);
        }
        if(root->rc!=NULL){
            postordertraversal(root->rc);
        }
        printf("%d ",root->e);
        
    }
    
}
void preordertraversal(bt root){
    if(root!=NULL){
        printf("%d ",root->e);
        if(root->lc!=NULL){
            preordertraversal(root->lc);
        }
        if(root->rc!=NULL){
            preordertraversal(root->rc);
        }
        
    }
    else{
        return;
        
    }
}

void inordertraversal(bt root){
    if(root!=NULL){
        
        if(root->lc!=NULL){
            inordertraversal(root->lc);
        }
        printf("%d ",root->e);
        if(root->rc!=NULL){
            inordertraversal(root->rc);
        }
        
    }
    else{
        return;
        
    }
}


int main()
{
    bt t=(bt)malloc(sizeof(struct node));
    t=create(5);
    
    bt tc1=(bt)malloc(sizeof(struct node));
    tc1=createchild(t,6);
    
    bt tc2=(bt)malloc(sizeof(struct node));
    tc2=createchild(t,7);
    
    bt tc3=(bt)malloc(sizeof(struct node));
    tc3=createchild(tc1,8);
    
    printf("Inorder:");
    inordertraversal(t);
    
    printf("\nPreorder:");
    preordertraversal(t);
    
    printf("\nPostorder:");
    postordertraversal(t);
    return 0;
}