#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct part{
    char e;
    struct part* next;
};
typedef struct part* node;
node push(node top,char x){
    node l=(node)malloc(sizeof(struct part));
    l->e=x;
    l->next=top->next;
    top->next=l;
    return top;
}
/*node insert(node top,int x,int pos){
    node p=top;
    int i=0;
    while(i<pos && p!=NULL){
        p=p->next;
        i++;

    }
    if(p==NULL){
        return top;   
    }
    node temp=(node)malloc(sizeof(struct part));
    temp->e=x;
    temp->next=p->next;
    p->next=temp;
    return top;
}*/

char pop(node top){
    if(top->next==NULL){
        return '\0';
    }
    node p=top->next;
    top->next=p->next;
    char a=p->e;
    free(p);
    return a;
}
char peek(node top){
    if(top!=NULL && top->next!=NULL) {
        char b=(top->next->e);
        return b;
    }
    return '\0';    
}
struct stack{
    node top;
};

node createstack(void){
    node top=(node)malloc(sizeof(struct part));
    top->e='\0';
    top->next=NULL;
    return top;
}

int preference(char s){
    switch(s){
        case '+':
        case '-': return (int)1;
        break;
        case '*':
        case '/':
        return 2;
        break;
        default:
        return -1;
    }
}

char* infix2postfix(char *s,char* a,node top,int k){
    int i=0;
    //node top=createstack();
    while(s[i]!='\0'){
        if(isalnum(s[i])){
            a[k++]=s[i];
        }
        else if(s[i]=='+' || s[i]=='*'||s[i]=='/'||s[i]=='-'){
            while(preference(peek(top)) >= preference(s[i])) {
                a[k++] = pop(top);
            }
            top=push(top,s[i]);
        }
        else if(s[i]=='('){
            top=push(top,s[i]);
        }
        else if(s[i]==')'){
            char x;
            while((x = pop(top)) != '(' && x != '\0') {
                a[k++] = x;
            }
        }
        i++;
    }
    while(top->next!=NULL){
        a[k++]=pop(top);
    }
    return a;
}

char* reverse(char*s){
    int i=0;
    
}
int main(void){
    char *str="a+b*c-(d/e+f)*g";
    node top = createstack();
    char a[128] = {0};
    infix2postfix(str, a, top, 0);
    int i = 0;
    while (a[i]!='\0') {
        printf("%c", a[i]);
        i++;
    }
    return 0;
}
