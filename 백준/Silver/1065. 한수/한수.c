#include <stdio.h>

int is_hansu(int num) {
    if (num < 100) return 1;

    int a = num / 100;
    int b = (num / 10) % 10;
    int c = num % 10;

    return (a - b) == (b - c);
}

int main() {
    int num, count = 0;
    scanf("%d", &num);

    for (int i = 1; i <= num; i++) {
        if (is_hansu(i)) {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}
