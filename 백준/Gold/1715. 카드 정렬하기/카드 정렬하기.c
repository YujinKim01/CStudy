#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP 100001

int heap[MAX_HEAP];
int heapSize = 0;

void push(int x) {
    int i = ++heapSize;

    while (i != 1 && x < heap[i / 2]) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = x;
}

int pop() {
    int min = heap[1];
    int last = heap[heapSize--];

    int parent = 1, child = 2;
    while (child <= heapSize) {
        if (child < heapSize && heap[child] > heap[child + 1]) {
            child++;
        }
        if (last <= heap[child]) break;

        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = last;
    return min;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        push(x);
    }

    int result = 0;
    while (heapSize > 1) {
        int first = pop();
        int second = pop();
        int sum = first + second;
        result += sum;
        push(sum);
    }

    printf("%d\n", result);
    return 0;
}