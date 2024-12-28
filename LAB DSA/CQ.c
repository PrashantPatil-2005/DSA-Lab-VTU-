#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3

char queue[MAX_SIZE];
int rear = -1, front = 0, count = 0;

void insert() 
{ 
    char element;
    if (count == MAX_SIZE) {
        printf("Circular Queue Overflow\n");
        return;
    }

    rear = (rear + 1) % MAX_SIZE;
    printf("Enter the element: ");
    scanf(" %c", &element);
    queue[rear] = element;
    count++;
}

void delete() 
{ 
    if (count == 0) {
        printf("Circular Queue is empty\n");
        return;
    }

    printf("Element deleted from circular queue: %c\n", queue[front]);
    front = (front + 1) % MAX_SIZE;
    count--;
}

void display()
{ 
    if (count == 0) {
        printf("Circular Queue is empty\n");
        return;
    }

    printf("Circular Queue contents:\n");
    for (int i = front, j = 0; j < count; j++) {
        printf("%d : %c\n", i, queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
}

int main()
{ 
    int choice;

    while (1) { 
        printf("1: Insert\n2: Delete\n3: Display\n4: Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            default: exit(0);
        } 
    } 
}
