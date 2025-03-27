#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    int score[301];
    int ans[301];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &score[i]);
    }

    if (n == 1) {
        printf("%d\n", score[0]);
        return 0;
    }

    ans[0] = score[0];
    ans[1] = score[0] + score[1];
    ans[2] = max(score[0] + score[2], score[1] + score[2]);

    for (int i = 3; i < n; i++) {
        ans[i] = max(ans[i - 2], ans[i - 3] + score[i - 1]) + score[i];
    }

    printf("%d\n", ans[n - 1]);
    return 0;
}