#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

typedef struct {
    int data[MAX_N];
    int front, rear;
    int is_reversed;
} Deque;

void init_deque(Deque *dq) {
    dq->front = 0;
    dq->rear = 0;
    dq->is_reversed = 0;
}

void push_back(Deque *dq, int value) {
    dq->data[dq->rear++] = value;
}

int pop_front(Deque *dq) {
    if (dq->front == dq->rear) return -1;
    return dq->data[dq->front++];
}

int pop_back(Deque *dq) {
    if (dq->front == dq->rear) return -1;
    return dq->data[--dq->rear];
}

void print_deque(Deque *dq) {
    printf("[");
    if (dq->is_reversed) {
        for (int i = dq->rear - 1; i >= dq->front; i--) {
            printf("%d", dq->data[i]);
            if (i > dq->front) printf(",");
        }
    } else {
        for (int i = dq->front; i < dq->rear; i++) {
            printf("%d", dq->data[i]);
            if (i < dq->rear - 1) printf(",");
        }
    }
    printf("]\n");
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char p[100001];
        int n;
        scanf("%s", p);
        scanf("%d", &n);

        Deque dq;
        init_deque(&dq);

        char input[500001];
        scanf("%s", input);

        char *ptr = strtok(input, "[,]");
        while (ptr) {
            push_back(&dq, atoi(ptr));
            ptr = strtok(NULL, "[,]");
        }

        int error_flag = 0;
        for (int i = 0; p[i] != '\0'; i++) {
            if (p[i] == 'R') {
                dq.is_reversed ^= 1;
            } else if (p[i] == 'D') {
                int result = dq.is_reversed ? pop_back(&dq) : pop_front(&dq);
                if (result == -1) {
                    error_flag = 1;
                    break;
                }
            }
        }

        if (error_flag) {
            printf("error\n");
        } else {
            print_deque(&dq);
        }
    }
    return 0;
}