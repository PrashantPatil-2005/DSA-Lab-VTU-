#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DAYS 3

struct activity {
    char *day;
    int date;
    char *desc;
};
typedef struct activity plan;

plan *create() 
{
    plan *t = (plan *)malloc(sizeof(plan) * DAYS);
    if (t == NULL) {
        printf("Sufficient memory not allocated\n");
        return NULL;
    }
    return t;
}

void read(plan *p) 
{
    for (int i = 0; i < DAYS; i++) 
    {
        p[i].day = (char *)malloc(9 * sizeof(char));
        if (p[i].day == NULL) 
        {
            printf("Memory allocation failed for day name.\n");
            return;
        }
        printf("Enter name of the day: ");
        scanf(" %s", p[i].day);

        printf("Enter date of the day: ");
        scanf("%d", &(p[i].date));

        p[i].desc = (char *)malloc(400 * sizeof(char));
        if (p[i].desc == NULL) 
        {
            printf("Memory allocation failed for description.\n");
            return;
        }
        printf("Enter description of the activity: ");
        scanf(" %[^\n]", p[i].desc);
        
        char *temp = (char *)realloc(p[i].desc, strlen(p[i].desc) + 1);
        if (temp == NULL) 
        {
            printf("Memory reallocation failed for description.\n");
            return;
        }
        p[i].desc = temp;
    }
}

void display(plan *p) 
{
    printf("**** Activity description for %d days ****\n", DAYS);
    for (int i = 0; i < DAYS; i++) {
        printf("\nName of the day: %s", p[i].day);
        printf("\nDate of the day: %d", p[i].date);
        printf("\nActivity description: %s\n", p[i].desc);
    }
}

int main() 
{
    plan *cal = NULL;
    cal = create();

    if (cal == NULL) 
    {
        printf("Memory allocation failed.\n");
        return -1;
    }

    read(cal);
    display(cal);
    return 0;
}
