#include <stdio.h>

long long solution(int n) {
    const int MOD = 1234567;
    long long a = 1, b = 2, temp;

    if (n == 1) return 1;
    if (n == 2) return 2;

    for (int i = 3; i <= n; i++) {
        temp = (a + b) % MOD;
        a = b;
        b = temp;
    }
    
    return b;
}