#include <stdio.h>
void h(int n, char S, char T, char D) //std
{
    if (n == 0)
    return;  
    h(n - 1, S, D, T);//sdt
    printf("Move disc %d from %c to %c\n", n, S, D);
    h(n - 1, T, S, D);//tsd
}

int main() 
{
    int n;
    printf("Enter number of discs\n");
    scanf("%d", &n);
    h(n, 'A', 'B', 'C');
    
    return 0;
}
