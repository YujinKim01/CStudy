#include <stdio.h>

int main() {
    int n, k;
    int coin[101];
    int ans[10001] = {0};

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &coin[i]);
    }

    ans[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= k; j++) {
            ans[j] += ans[j - coin[i]];
        }
    }

    printf("%d\n", ans[k]);
    return 0;
}