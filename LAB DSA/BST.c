#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int data;
    struct tree *rlink, *llink;
} *TNODE;

TNODE getnode() {
    TNODE temp = (TNODE)malloc(sizeof(struct tree));
    if(temp == NULL) {
        printf("Out of memory!!!\n");
        return NULL;
    }
    return temp;
}

TNODE insert(TNODE root) {
    int n, ele, i, flag;
    TNODE temp, prev;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter element to be inserted: ");
        scanf("%d", &ele);
        TNODE newN = getnode();
        newN->data = ele;
        newN->rlink = newN->llink = NULL;

        if(root == NULL) {
            root = newN;
            continue;
        }

        prev = NULL;
        temp = root;
        flag = 0;

        while(temp != NULL) {
            prev = temp;
            if(ele == temp->data) {
                printf("Redundant data\n");
                flag = 1;
                break;
            }
            if(ele < temp->data)
                temp = temp->llink;
            else
                temp = temp->rlink;
        }

        if(flag == 1) continue;
        if(ele < prev->data)
            prev->llink = newN;
        else
            prev->rlink = newN;
    }
    return root;
}

void inorder(TNODE root) {
    if(root != NULL) {
        inorder(root->llink);
        printf("%d\n", root->data);
        inorder(root->rlink);
    }
}

void preorder(TNODE root) {
    if(root != NULL) {
        printf("%d\n", root->data);
        preorder(root->llink);
        preorder(root->rlink);
    }
}

void postorder(TNODE root) {
    if(root != NULL) {
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d\n", root->data);
    }
}

int search(TNODE root, int key) {
    while(root != NULL) {
        if(root->data == key)
            return 1; // Successful search
        if(key < root->data)
            root = root->llink;
        else
            root = root->rlink;
    }
    return -1; // Unsuccessful search
}

void main() {
    TNODE root = NULL;
    int choice, ele, key, flag;

    for(;;) {
        printf("\nEnter:\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Search\n6. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                root = insert(root);
                break;
            case 2:
                if(root == NULL) {
                    printf("Tree is empty\n");
                } else {
                    printf("The contents are:\n");
                    inorder(root);
                }
                break;
            case 3:
                if(root == NULL) {
                    printf("Tree is empty\n");
                } else {
                    printf("The contents are:\n");
                    preorder(root);
                }
                break;
            case 4:
                if(root == NULL) {
                    printf("Tree is empty\n");
                } else {
                    printf("The contents are:\n");
                    postorder(root);
                }
                break;
            case 5:
                printf("Enter the node to be searched:\n");
                scanf("%d", &key);
                flag = search(root, key);
                if(flag == -1)
                    printf("Unsuccessful search!!!\n");
                else
                    printf("Successful search!!!\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}