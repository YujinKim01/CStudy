#include <stdio.h>

#define MAX 100000

int stack[MAX];
int top = -1;

void push(int value) {
    stack[++top] = value; 
}

void pop() {
    if (top >= 0) {
        top--;
    }
}

int main() {
    int K, num, ans = 0;
    scanf("%d", &K);

    for (int i = 0; i < K; i++) {
        scanf("%d", &num);

        if (num == 0) {
            pop();
        } else {
            push(num);
        }
    }

    for (int i = 0; i <= top; i++) {
        ans += stack[i];
    }

    printf("%d\n", ans);

    return 0;
}