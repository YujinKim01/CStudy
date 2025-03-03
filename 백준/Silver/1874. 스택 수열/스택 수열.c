#include <stdio.h>

#define MAX 100000

int stack[MAX];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

void pop() {
    top--;
}

int main() {
    int n;
    scanf("%d", &n);

    int sequence[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }

    int curr = 1;
    int index = 0;
    char result[MAX * 2];
    int resultindex = 0;

    for (int i = 0; i < n; i++) {
        int target = sequence[i];

        while (curr <= target) {
            push(curr++);
            result[resultindex++] = '+';
        }

        if (stack[top] == target) {
            pop();
            result[resultindex++] = '-';
        } else {
            printf("NO\n");
            return 0;
        }
    }

    for (int i = 0; i < resultindex; i++) {
        printf("%c\n", result[i]);
    }

    return 0;
}