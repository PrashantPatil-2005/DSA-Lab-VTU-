#include <stdio.h>
#include <stdlib.h>

int a[50][50], n, bvisited[50], dvisited[50];
int q[20], front = -1, rear = -1;
int s[20], top = -1, count = 0;

void bfs(int v) {
    int cur;
    bvisited[v] = 1;
    q[++rear] = v;
    while (front != rear) {
        cur = q[++front];
        for (int i = 1; i <= n; i++) {
            if (a[cur][i] == 1 && bvisited[i] == 0) {
                q[++rear] = i;
                bvisited[i] = 1;
                printf("%d ", i);
            }
        }
    }
}

void dfs(int v) {
    dvisited[v] = 1;
    s[++top] = v;
    for (int i = 1; i <= n; i++) {
        if (a[v][i] == 1 && dvisited[i] == 0) {
            printf("%d ", i);
            dfs(i);
        }
    }
}

int main() {
    int ch, start;
    printf("\nEnter the number of vertices in graph: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    }

    for (int i = 1; i <= n; i++) {
        bvisited[i] = 0;
        dvisited[i] = 0;
    }

    printf("\nEnter the starting vertex: ");
    scanf("%d", &start);

    while (1) {
        printf("\nMENU");
        printf("\n==>1. BFS: Print all nodes reachable from a given starting node");
        printf("\n==>2. DFS: Print all nodes reachable from a given starting node");
        printf("\n==>3: Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nNodes reachable from starting vertex %d are: ", start);
                bfs(start);
                break;
            case 2:
                printf("\nNodes reachable from starting vertex %d are: ", start);
                dfs(start);
                break;
            case 3:
                exit(0);
            default:
                printf("\nPlease enter a valid choice:");
        }
    }
}
