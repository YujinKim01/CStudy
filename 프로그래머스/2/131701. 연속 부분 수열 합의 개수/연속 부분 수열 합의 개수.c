#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ELEMENTS 1000
#define MAX_SUM 1000000

bool sum_exists[MAX_SUM + 1];

int solution(int elements[], size_t elements_len) {
    int answer = 0;

    int extended_elements[2 * MAX_ELEMENTS];
    for (size_t i = 0; i < elements_len; i++) {
        extended_elements[i] = elements[i];
        extended_elements[i + elements_len] = elements[i];
    }

    memset(sum_exists, false, sizeof(sum_exists));

    for (size_t len = 1; len <= elements_len; len++) {
        for (size_t start = 0; start < elements_len; start++) {
            int sum = 0;
            for (size_t k = 0; k < len; k++) {
                sum += extended_elements[start + k];
            }
            if (!sum_exists[sum]) {
                sum_exists[sum] = true;
                answer++;
            }
        }
    }

    return answer;
}
