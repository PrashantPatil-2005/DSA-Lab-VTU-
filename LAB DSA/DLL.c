#include <stdio.h>
#include <stdlib.h>
// #define SIZE 20

typedef struct node {
    char SSN[10], name[20], dept[30], desig[30];
    float sal;
    long int ph;
    struct node *llink, *rlink;
} *NODE;

// Function to allocate a new node
NODE getnode() {
    NODE temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->llink = temp->rlink = NULL;
    return temp;
}

NODE ins_front(NODE first) {
    NODE temp = getnode();
    printf("Enter SSN, Name, Dept, Desig, Salary, Phone of the Employee:\n");
    scanf("%s%s%s%s%f%ld", temp->SSN, temp->name, temp->dept, temp->desig, &temp->sal, &temp->ph);

    temp->rlink = first;
    if (first != NULL)
        first->llink = temp;

    return temp;
}

NODE ins_rear(NODE first) {
    NODE temp = getnode();
    printf("Enter SSN, Name, Dept, Desig, Salary, Phone of the Employee:\n");
    scanf("%s%s%s%s%f%ld", temp->SSN, temp->name, temp->dept, temp->desig, &temp->sal, &temp->ph);

    if (first == NULL)
        return temp;

    NODE cur = first;
    while (cur->rlink != NULL)
        cur = cur->rlink;

    cur->rlink = temp;
    temp->llink = cur;
    return first;
}

NODE del_front(NODE first) {
    if (first == NULL) {
        printf("DLL is empty\n");
        return NULL;
    }

    printf("Information to be deleted is...\n");
    printf("%s\t%s\t%s\t%s\t%f\t%ld\n", first->SSN, first->name, first->dept, first->desig, first->sal, first->ph);

    NODE temp = first->rlink;
    if (temp != NULL)
        temp->llink = NULL;

    free(first);
    return temp;
}

NODE del_rear(NODE first) {
    if (first == NULL) {
        printf("DLL is empty\n");
        return NULL;
    }

    NODE temp = first, prev = NULL;

    while (temp->rlink != NULL) {
        prev = temp;
        temp = temp->rlink; 
    }

    printf("Information to be deleted is...\n");
    printf("%s\t%s\t%s\t%s\t%f\t%ld\n", temp->SSN, temp->name, temp->dept, temp->desig, temp->sal, temp->ph);
    free(temp);

    if (prev != NULL) {
        prev->rlink = NULL;
        return first;
    }

    return NULL;
}

NODE create(NODE first) {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        first = ins_rear(first);

    return first;
}

void status(NODE first) {
    int count = 0;

    if (first == NULL) {
        printf("DLL is empty\n");
        return;
    }

    for (; first != NULL; first = first->rlink, count++);
         printf("Number of nodes in DLL is %d\n", count);
}

void display(NODE first) {
    if (first == NULL) {
        printf("Contents of DLL are empty\n");
        return;
    }

    printf("Contents of the list from FIRST -> LAST:\n");
    NODE cur = first;
    while (cur != NULL) {
        printf("%s\t%s\t%s\t%s\t%f\t%ld\n", cur->SSN, cur->name, cur->dept, cur->desig, cur->sal, cur->ph);
        cur = cur->rlink;
    }

    printf("Contents of the list from LAST -> FIRST:\n");
    // Move to the last node
    while (first->rlink != NULL)
        first = first->rlink;

    // Print from last to first
    while (first != NULL) {
        printf("%s\t%s\t%s\t%s\t%f\t%ld\n", first->SSN, first->name, first->dept, first->desig, first->sal, first->ph);
        first = first->llink;
    }
}

int main() {
    NODE first = NULL;
    int ch;

    for (;;) {
        printf("1. Create N employees\n2. Status of DLL\n");
        printf("3. Insert front\n4. Insert rear\n5. Delete front\n");
        printf("6. Delete rear\n7. Display\n8. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: first = create(first); break;
            case 2: status(first); break;
            case 3: first = ins_front(first); break;
            case 4: first = ins_rear(first); break;
            case 5: first = del_front(first); break;
            case 6: first = del_rear(first); break;
            case 7: display(first); break;
            case 8: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
}
