#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WEIGHT 1000

long long solution(int weights[], size_t weights_len) {
    long long answer = 0;
    int weight_count[MAX_WEIGHT + 1] = {0}; 

    for (size_t i = 0; i < weights_len; i++) {
        weight_count[weights[i]]++;
    }

    for (int w = 100; w <= MAX_WEIGHT; w++) {
        if (weight_count[w] == 0) continue;

        if (weight_count[w] > 1) {
            answer += ((long long)weight_count[w] * (weight_count[w] - 1)) / 2;
        }

        if (w * 2 / 3 >= 100 && w * 2 % 3 == 0) {
            answer += (long long)weight_count[w] * weight_count[w * 2 / 3];
        }
        if (w * 2 / 4 >= 100 && w * 2 % 4 == 0) {
            answer += (long long)weight_count[w] * weight_count[w * 2 / 4];
        }
        if (w * 3 / 4 >= 100 && w * 3 % 4 == 0) {
            answer += (long long)weight_count[w] * weight_count[w * 3 / 4];
        }
    }

    return answer;
}
