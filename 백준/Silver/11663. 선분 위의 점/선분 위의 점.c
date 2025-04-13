#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int lower_bound(int* arr, int n, int target) {
    int l = 0, r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (arr[m] < target) l = m + 1;
        else r = m;
    }
    return l;
}

int upper_bound(int* arr, int n, int target) {
    int l = 0, r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (arr[m] <= target) l = m + 1;
        else r = m;
    }
    return l;
}

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int* points = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &points[i]);
    }

    qsort(points, N, sizeof(int), compare);

    for (int i = 0; i < M; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        int lower = lower_bound(points, N, start);
        int upper = upper_bound(points, N, end);
        printf("%d\n", upper - lower);
    }

    free(points);
    return 0;
}