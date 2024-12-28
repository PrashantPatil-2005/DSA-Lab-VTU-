#include <stdio.h>
#include <stdlib.h>
#define Max 3 

void insert(char q[], int *r, int *cnt) { 
    char ele; 
    if (*cnt == Max) 
    { 
        printf("C Queue overflow\n"); 
        return; 
    } 

    *r = (*r + 1) % Max; 
    printf("Enter the element: "); 
    scanf(" %c", &ele); 
    q[*r] = ele; 
    (*cnt)++; 
} 

void del(char q[], int *f, int *cnt) 
{ 
    if (*cnt == 0) 
    { 
        printf("C Queue is empty\n"); 
        return; 
    } 

    printf("Element deleted from circular queue is %c\n", q[*f]); 
    *f = (*f + 1) % Max; 
    (*cnt)--; 
} 

void display(char q[], int f, int cnt) 
{ 
    int i, j; 
    if (cnt == 0) 
    { 
        printf("Circular Queue is empty\n"); 
        return; 
    } 
    printf("Circular Queue contents are:\n"); 

    for (i = f, j = 0; j < cnt; j++) 
    { 
        printf("%d : %c\n", i, q[i]); 
        i = (i + 1) % Max; 
    } 
}

int main() 
{ 
    char q[Max]; 
    int r = -1, f = 0, cnt = 0; 
    int ch; 

    while(1) 
    { 
        printf("1: Insert\n2: Delete\n3: Display\n4: Exit\n"); 
        printf("Enter choice\n"); 
        scanf("%d", &ch); 
        switch(ch) 
        { 
            case 1: insert(q, &r, &cnt); break; 
            case 2: del(q, &f, &cnt); break; 
            case 3: display(q, f, cnt); break; 
            default: exit(0); 
        } 
    } 
} 


