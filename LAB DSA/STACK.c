#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELE 4

int stack[MAX_ELE];
int top = -1;

void push() {
    if (top == MAX_ELE - 1) {
        printf("Stack overflow\n");
        return;
    }
    int ele;
    printf("Enter the element: ");
    scanf("%d", &ele);
    stack[++top] = ele;
    printf("Element pushed: %d\n", ele);
}

void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return;
    }
    printf("Element popped: %d\n", stack[top--]);
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements (from top):\n");
    for (int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}

void status() {
    printf("Used: %d\n", top + 1);
    printf("Free: %d\n", MAX_ELE - (top + 1));
}

void checkPalindrome(char *str) {
    int len = strlen(str), tempTop = -1;
    char tempStack[MAX_ELE];

    if (len > MAX_ELE) {
        printf("String too long for the stack\n");
        return;
    }

    for (int i = 0; i < len; i++) 
        tempStack[++tempTop] = str[i];
    for (int i = 0; i < len; i++) {
        if (tempStack[tempTop--] != str[i]) {
            printf("Not a palindrome\n");
            return;
        }
    }
    printf("It's a palindrome\n");
}

int main() {
    int choice;
    char str[MAX_ELE + 1] = "ada";

    while (1) {
        printf("\n1: Push\n2: Pop\n3: Check Palindrome\n4: Display\n5: Status\n6: Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: checkPalindrome(str); break;
            case 4: display(); break;
            case 5: status(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
