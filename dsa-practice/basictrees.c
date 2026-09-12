#include <stdio.h>
#include<stdlib.h>

struct node{
    int v;
    struct node* f;
    struct node* ns;
};
typedef struct node* tree;
tree create(){
    tree t=(tree)malloc(sizeof(struct node));
    if(t!=NULL){
        t->v=0;
        t->f=NULL;
        t->ns=NULL;
    }
    return t;
}
tree createchild(tree t,int c){
    if(t->f==NULL){
        t->f=(tree)malloc(sizeof(struct node));
        t->f->v=c;
        return t->f;
    }
    else{
        t->f->ns=(tree)malloc(sizeof(struct node));
        t->f->ns->v=c;
        return t->f->ns;
    }
}
int height(tree t){
    if(t==NULL){
        return 0;
        
    }
    else{
        int h=0;
        if(t==NULL){
            return (int)-1;
        }

        tree temp1=t->f;
        if(t->f==NULL){
            return 0;
        }
        else
        {
            int temp=height(temp1);
            while(temp1!=NULL){
                int x=height(temp1);
                if(x>temp){
                    temp=x;
                }
                temp1=temp1->ns;
            }
            return temp+1;
            
        }
    }
}
//boolean isavl(tree t){

    


int main()
{
    printf("Hello World");
    tree t=(tree)malloc(sizeof(struct node));
    t=create();
    t->v=5;
    tree tc1=(tree)malloc(sizeof(struct node));
    tc1=createchild(t,6);
    tree tc2=(tree)malloc(sizeof(struct node));
    tc2=createchild(t,7);
    int h=height(t);
    printf("Height of the tree nodes: %d %d %d\n", h,height(tc1),height(tc2));

    return 0;
} 