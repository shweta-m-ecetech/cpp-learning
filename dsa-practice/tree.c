
#include <stdio.h>
#include <stdlib.h>

struct node {
    int v;
    struct node* rc;
    struct node* lc;
};

typedef struct node* bt;

bt create() {
    bt t = (bt)malloc(sizeof(struct node));
    if (t != NULL) {
        t->v = 0;
        t->lc = NULL;
        t->rc = NULL;
    }
    return t;
}

bt createchild(bt t, int c) {
    if (t == NULL) {
        return NULL;
    }

    if (t->lc == NULL) {
        t->lc = (bt)malloc(sizeof(struct node));
        t->lc->v = c;
        t->lc->lc = NULL;
        t->lc->rc = NULL;
        return t->lc;
    }

    bt curr = t->lc;
    while (curr->rc != NULL) {
        curr = curr->rc;
    }

    curr->rc = (bt)malloc(sizeof(struct node));
    curr->rc->v = c;
    curr->rc->lc = NULL;
    curr->rc->rc = NULL;
    return curr->rc;
}

int main() {
    printf("Hello World");
    return 0;
}