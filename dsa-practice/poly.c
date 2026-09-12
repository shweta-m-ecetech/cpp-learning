#include <stdio.h>
#include <stdlib.h>

struct polynode {
    int coeff;
    int power;
    struct polynode *next;
};

typedef struct polynode *poly;

poly create_node(int coeff, int power) {
    poly node = (poly)malloc(sizeof(struct polynode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    node->coeff = coeff;
    node->power = power;
    node->next = NULL;
    return node;
}

poly init(int degree) {
    poly head = create_node(0, -1);
    poly tail = head;

    for (int i = 0; i <= degree; i++) {
        int c;
        if (scanf("%d", &c) != 1) {
            fprintf(stderr, "Invalid polynomial input.\n");
            exit(1);
        }

        if (c != 0) {
            tail->next = create_node(c, i);
            tail = tail->next;
        }
    }

    return head;
}

poly add(poly p1, poly p2, poly r) {
    poly a = p1->next;
    poly b = p2->next;
    poly tail = r;

    tail->next = NULL;

    while (a != NULL && b != NULL) {
        if (a->power > b->power) {
            tail->next = create_node(a->coeff, a->power);
            a = a->next;
        } else if (b->power > a->power) {
            tail->next = create_node(b->coeff, b->power);
            b = b->next;
        } else {
            int sum = a->coeff + b->coeff;
            if (sum != 0) {
                tail->next = create_node(sum, a->power);
            }
            a = a->next;
            b = b->next;
        }

        tail = tail->next;
    }

    while (a != NULL) {
        tail->next = create_node(a->coeff, a->power);
        a = a->next;
        tail = tail->next;
    }

    while (b != NULL) {
        tail->next = create_node(b->coeff, b->power);
        b = b->next;
        tail = tail->next;
    }

    return r;
}

void display(poly p) {
    poly d = p->next;

    if (d == NULL) {
        printf("0\n");
        return;
    }

    while (d != NULL) {
        printf("%dx^%d", d->coeff, d->power);
        if (d->next != NULL) {
            printf(" + ");
        }
        d = d->next;
    }
    printf("\n");
}

poly multiply(poly a,poly b,poly c){
    poly p1=a->next;
    poly p2=a->next;
    poly p3=c->next;
    

}
int main(void) {
    poly a = init(2);
    poly b = init(2);
    poly c = create_node(0, -1);

    poly p = add(a, b, c);
    display(p);

    return 0;
}
