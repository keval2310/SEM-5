#include <stdio.h>

int arr[100];
int top = -1;
int maxSize;

void initStack(int n) {
    maxSize = n;
    top = -1;
}

void push(int x) {
    if (top >= maxSize - 1) {
        printf("Stack is full\n");
    } else {
        top++;
        arr[top] = x;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return 0;
    } else {
        int popped = arr[top];
        arr[top] = 0;
        top--;
        printf("%d\n", popped);
        return popped;
    }
}

void displayStack() {
    for (int i = 0; i <= top; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int peep(int i) {
    if (top - i + 1 < 0) {
        printf("Stack is empty\n");
        return 0;
    } else {
        printf("%d\n", arr[top - i + 1]);
        int value = arr[top - i + 1];
        arr[top - i + 1] = 0;
        return value;
    }
}

void change(int i, int x) {
    if (top - i + 1 < 0) {
        printf("Stack is empty\n");
    } else {
        arr[top - i + 1] = x;
    }
}

int main() {
    initStack(5);
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    displayStack();
    pop();
    displayStack();
    peep(3);
    displayStack();
    change(3, 5);
    displayStack();
    return 0;
}