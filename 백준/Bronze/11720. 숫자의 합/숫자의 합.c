#include <stdio.h>

int main() {
    int t, sum = 0;
    char num[101];

    scanf("%d", &t);
    scanf("%s", num);

    for (int i = 0; i < t; i++) {
        sum += num[i] - '0';
    }

    printf("%d\n", sum);
    return 0;
}