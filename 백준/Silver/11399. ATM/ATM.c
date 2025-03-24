#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    scanf("%d", &N);

    int time[1000];
    for (int i = 0; i < N; i++) {
        scanf("%d", &time[i]);
    }

    qsort(time, N, sizeof(int), compare);

    int total = 0;
    int sum = 0;

    for (int i = 0; i < N; i++) {
        sum += time[i];
        total += sum;
    }

    printf("%d\n", total);
    return 0;
}