#include <stdio.h>
#include <stdlib.h>

int solution(int order[], size_t order_len) {
    int answer = 0;
    int index = 0;
    int current_box = 1;
    int* stack = (int*)malloc(order_len * sizeof(int));
    int top = -1;

    while (current_box <= order_len) {
        if (current_box == order[index]) {
            answer++;
            index++;
            current_box++;
        }
        else if (top >= 0 && stack[top] == order[index]) {
            top--;
            answer++;
            index++;
        }
        else {
            stack[++top] = current_box;
            current_box++;
        }
    }
    while (top >= 0 && stack[top] == order[index]) {
        top--;
        answer++;
        index++;
    }
    free(stack);
    return answer;
}