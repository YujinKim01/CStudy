#include <stdio.h>

#define MAX 1000000

int N;
int A[MAX];
int result[MAX];
int stack[MAX];
int top = -1;

void push(int value) {
    stack[++top] = value;
}
int pop() {
    return stack[top--];
}
int isempty() {
    return top == -1;
}
int peek() {
    return stack[top];
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < N; i++) {
        while (!isempty() && A[peek()] < A[i]) {
            result[pop()] = A[i];
        }
        push(i);
    }

    while (!isempty()) {
        result[pop()] = -1;
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
