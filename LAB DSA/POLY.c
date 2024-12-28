#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct node {
    int coef, xexp, yexp, zexp;
    struct node *link;
};
typedef struct node *NODE;

NODE getnode() {
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    if(temp == NULL) {
        printf("Memory not available\n");
        exit(0);
    }
    temp->link = temp;
    return temp;
}

void read_poly(NODE p1, int n) {
    NODE temp, next;
    for(int i = 0; i < n; i++) {
        temp = getnode();
        printf("Enter coefficient and powers (coef xexp yexp zexp): ");
        scanf("%d%d%d%d", &(temp->coef), &(temp->xexp), &(temp->yexp), &(temp->zexp));
        next = p1->link;
        p1->link = temp;
        temp->link = next;
    }
}

void display(NODE p) {
    NODE cur = p->link;
    while(cur != p) {
        printf(" + %d*x^%d*y^%d*z^%d", cur->coef, cur->xexp, cur->yexp, cur->zexp);
        cur = cur->link;
    }
    printf("\n");
}

void insert(NODE p, int coef, int xexp, int yexp, int zexp) {
    NODE next;
    NODE temp = getnode();
    temp->coef = coef;
    temp->xexp = xexp;
    temp->yexp = yexp;
    temp->zexp = zexp;

    next = p->link;
    p->link = temp;
    temp->link = next;
}

NODE compare(NODE p, NODE res) {
    NODE cur=p->link;
    while(cur != p) {
        if((cur->xexp == res->xexp) && (cur->yexp == res->yexp) && (cur->zexp == res->zexp))
            return cur;
        cur = cur->link;
    }
    return NULL;
}

void add(NODE p1, NODE p2, NODE p3) 
{
    NODE cur, res;

    cur = p1->link;
    while(cur != p1) 
    {
        res = compare(p2, cur);
        if(res != NULL) 
        {
            insert(p3, cur->coef + res->coef, cur->xexp, cur->yexp, cur->zexp);
        } 
        else 
        {
            insert(p3, cur->coef, cur->xexp, cur->yexp, cur->zexp);
        }
        cur = cur->link;
    }
    cur = p2->link;
    while(cur != p2) 
    {
        if(compare(p1, cur) == NULL) 
        {
            insert(p3, cur->coef, cur->xexp, cur->yexp, cur->zexp);
        }
        cur = cur->link;
    }
}

void evaluate(NODE p) {
    int x, y, z, res = 0;
    NODE cur;
    printf("Enter value of x, y, and z: ");
    scanf("%d%d%d", &x, &y, &z);
    for(cur = p->link; cur != p; cur = cur->link)
        res = res + cur->coef * pow(x, cur->xexp) * pow(y, cur->yexp) * pow(z, cur->zexp);
    printf("Evaluation of polynomial is %d\n", res);
}

int main() {
    int n;
    NODE p1, p2, p3;
    p1 = getnode();
    p2 = getnode();
    p3 = getnode();
    int ch;
    while(1) {
        printf("1. Evaluate\n2. Polynomial addition\n3. Exit\n");
        printf("Choice: "); scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter the number of terms in P: ");
                scanf("%d", &n);

                read_poly(p1, n);

                printf("Terms in polynomial are...\n");
                display(p1);
                evaluate(p1);
                break;
            case 2:
                printf("Enter the number of terms in P1: ");
                scanf("%d", &n);
                read_poly(p1, n);

                printf("Enter the number of terms in P2: ");
                scanf("%d", &n);
                read_poly(p2, n);

                printf("Entered Polynomials are:\n");
                display(p1);
                display(p2);

                printf("Polynomial after addition:");
                add(p1, p2, p3);
                display(p3);
                
                break;
            default:
                exit(0);
        }
    }
}
