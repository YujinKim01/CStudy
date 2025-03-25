#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int N;
    scanf("%d", &N);

    int prev, curr;
    scanf("%d", &prev);

    int up_len = 1, down_len = 1;
    int result = 1;

    for (int i = 1; i < N; i++) {
        scanf("%d", &curr);

        if (curr >= prev) {
            up_len++;
        } else {
            up_len = 1;
        }

        if (curr <= prev) {
            down_len++;
        } else {
            down_len = 1;
        }

        result = max(result, max(up_len, down_len));
        prev = curr;
    }

    printf("%d\n", result);
    return 0;
}