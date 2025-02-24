#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000001

int compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int solution(int k, int tangerine[], size_t tangerine_len) {
    int count[MAX_SIZE] = {0};
    int unique_count = 0;

    for (size_t i = 0; i < tangerine_len; i++) {
        if (count[tangerine[i]] == 0) {
            unique_count++;
        }
        count[tangerine[i]]++;
    }

    int *counts = (int *)malloc(unique_count * sizeof(int));
    int index = 0;
    
    for (int i = 0; i < MAX_SIZE; i++) {
        if (count[i] > 0) {
            counts[index++] = count[i];
        }
    }

    qsort(counts, unique_count, sizeof(int), compare);

    int sum = 0;
    int min_variety = 0;
    
    for (int i = 0; i < unique_count; i++) {
        sum += counts[i];
        min_variety++;
        if (sum >= k) break;
    }

    free(counts);
    return min_variety;
}