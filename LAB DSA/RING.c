#include<stdio.h>
#include<string.h>

void main() {
    char s[20], pat[20], rep[20], ans[30];
    int i, j, k = 0, flag;

    printf("\nEnter string: ");
    scanf("%s", s);
    printf("\nEnter pattern: ");
    scanf("%s", pat);
    printf("\nEnter replacement: ");
    scanf("%s", rep);

    for (i = 0; s[i] != '\0'; i++) 
    {
        flag = 1;
        for (j = 0; pat[j] != '\0'; j++) 
        {
            if (s[i + j] != pat[j]) 
            {
                flag = 0;
                break;
            }
        }

        if (flag) 
        {
            for (j = 0; rep[j] != '\0'; j++) 
            {
                ans[k] = rep[j];
                k++;
            }
            i =i + j - 1;
        }
        else
        {
            ans[k] = s[i];
            k++;
        }
    }

    ans[k] = '\0';
    printf("Updated string: %s\n", ans);
}
