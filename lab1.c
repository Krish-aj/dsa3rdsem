#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define days 3

struct activity {
    char* day;
    int date;
    char* desc;
};
typedef struct activity plan;

plan* create();
void read(plan*);
void display(plan*);
void free_memory(plan*);

int main() {
    plan *cal = NULL;
    cal = create();
    read(cal);
    display(cal);
    free_memory(cal); // Free dynamically allocated memory
    return 0;
}

plan* create() {
    plan *t = (plan*)malloc(sizeof(plan) * days);
    if (t == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return t;
}

void read(plan* p) {
    int i;
    for(i=0;i<days;i++){
        printf("enter the day: ");
        p[i].day=(char*)malloc(9);
        scanf("%s",p[i].day);

        printf("enter date: ");
        scanf("%d",&p[i].date);

        printf("enter description: ");
        p[i].desc=(char*)malloc(400);
        scanf(" %[^\n]",p[i].desc);
    }

}

void display(plan* p) {
    printf("Activities of %d days:\n", days);
    for (int i = 0; i < days; i++) {
        printf("Day: %s\n", p[i].day);
        printf("Date: %d\n", p[i].date);
        printf("Description: %s\n", p[i].desc);
    }
}

void free_memory(plan* p) {
    for (int i = 0; i < days; i++) {
        free(p[i].day);
        free(p[i].desc);
    }
    free(p);
}
