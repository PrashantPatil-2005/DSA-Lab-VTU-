#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELE 4

void status(int *s, int top) { 
    int used; 
    if (top == -1) 
        used = 0; 
    else 
        used = top + 1; 

    printf("%d locations of the stack are used up\n", used); 
    printf("%d locations of the stack are free\n", MAX_ELE - used); 
}

void display(int s[], int *top) { 
    int i; 
    if ((*top) == -1) 
        printf("stack empty\n"); 
    else { 
        printf("stack elements are\n"); 
        printf("TOS is: "); 
        for(i = (*top); i >= 0; i--) 
            printf("%d\n", s[i]); 
    } 
}

void push(int *s, int *top, int ele) { 
    if ((*top) == MAX_ELE - 1) { 
        printf("stack overflow\n"); 
        return; 
    } 
    (*top)++; 
    printf("enter the element: "); 
    scanf("%d", &ele); 
    s[*top] = ele; 
}

void pop(int s[], int *top) { 
    if ((*top) == -1) 
        printf("stack underflow\n"); 
    else { 
        printf("element popped is: %d\n", s[*top]); 
        (*top)--; 
    } 
}

void palindrome(char *s) { 
    int length = strlen(s); 
    int stack[MAX_ELE]; 
    int top = -1;
    
    // Push characters into the stack
    for (int i = 0; i < length; i++) 
        push(stack, &top, s[i]);

    // Check if the string is a palindrome
    for (int i = 0; i < length; i++) { 
        if (stack[top--] != s[i]) { 
            printf("String is not a palindrome\n"); 
            exit(0); 
        } 
    } 
    printf("String is a palindrome\n"); 
}

int main() { 
    int ch, top = -1; 
    int s[MAX_ELE]; 
    char str[10] = "mom"; 
    for (;;) { 
        printf("1: push\n2: pop\n3: palindrome\n4: display\n5: Status\n6: Exit\n"); 
        printf("Enter choice: "); 
        scanf("%d", &ch); 
        switch(ch) { 
            case 1: push(s, &top, 0); break;  // '0' will just act as a placeholder for now
            case 2: pop(s, &top); break; 
            case 3: palindrome(str); break; 
            case 4: display(s, &top); break; 
            case 5: status(s, top); break; 
            default: exit(0); 
        } 
    } 
}