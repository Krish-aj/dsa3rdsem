#include <stdio.h>
#include <stdlib.h>
#define MAX 10  // Total size of the array
#define STACKS 2  // Number of stacks

typedef struct {
    int top[STACKS];  // Array to store top indices for each stack
    int array[MAX];   // Shared array for multiple stacks
    int stackSize;    // Maximum size for each stack
} MultiStack;

// Initialize multiple stacks
void initialize(MultiStack *ms) {
    ms->stackSize = MAX / STACKS;
    for (int i = 0; i < STACKS; i++) {
        ms->top[i] = i * ms->stackSize - 1;  // Top of stack i starts before its segment
    }
}

// Push an element onto a specific stack
void push(MultiStack *ms, int stackNum, int value) {
    if (stackNum < 0 || stackNum >= STACKS) {
        printf("Invalid stack number!\n");
        return;
    }
    if (ms->top[stackNum] >= ((stackNum + 1) * ms->stackSize) - 1) {
        printf("Stack %d overflow!\n", stackNum);
        return;
    }
    ms->array[++ms->top[stackNum]] = value;
    printf("Pushed %d onto stack %d\n", value, stackNum);
}

// Pop an element from a specific stack
int pop(MultiStack *ms, int stackNum) {
    if (stackNum < 0 || stackNum >= STACKS) {
        printf("Invalid stack number!\n");
        return -1;
    }
    if (ms->top[stackNum] < stackNum * ms->stackSize) {
        printf("Stack %d underflow!\n", stackNum);
        return -1;
    }
    return ms->array[ms->top[stackNum]--];
}

// Display elements of a specific stack
void display(MultiStack *ms, int stackNum) {
    if (stackNum < 0 || stackNum >= STACKS) {
        printf("Invalid stack number!\n");
        return;
    }
    if (ms->top[stackNum] < stackNum * ms->stackSize) {
        printf("Stack %d is empty!\n", stackNum);
        return;
    }
    printf("Stack %d: ", stackNum);
    for (int i = ms->top[stackNum]; i >= stackNum * ms->stackSize; i--) {
        printf("%d ", ms->array[i]);
    }
    printf("\n");
}

int main() {
    MultiStack ms;
    initialize(&ms);

    push(&ms, 0, 10);
    push(&ms, 0, 20);
    push(&ms, 1, 30);
    push(&ms, 1, 40);

    display(&ms, 0);
    display(&ms, 1);

    printf("Popped from stack 0: %d\n", pop(&ms, 0));
    printf("Popped from stack 1: %d\n", pop(&ms, 1));

    display(&ms, 0);
    display(&ms, 1);

    return 0;
}
