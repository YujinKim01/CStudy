#include <stdio.h>

#define MAX 5
#define MOD 1000

int N;
long long B;
int A[MAX][MAX];
int result[MAX][MAX];
int temp[MAX][MAX];

void multiply(int res[MAX][MAX], int m1[MAX][MAX], int m2[MAX][MAX]) {
    int temp_result[MAX][MAX] = {0};
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++) {
                temp_result[i][j] += m1[i][k] * m2[k][j];
                temp_result[i][j] %= MOD;
            }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            res[i][j] = temp_result[i][j];
}

void power(int res[MAX][MAX], int base[MAX][MAX], long long exp) {
    // 단위행렬로 초기화
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            res[i][j] = (i == j);

    while (exp > 0) {
        if (exp % 2 == 1) {
            multiply(temp, res, base);
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    res[i][j] = temp[i][j];
        }
        multiply(temp, base, base);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                base[i][j] = temp[i][j];

        exp /= 2;
    }
}

int main() {
    scanf("%d %lld", &N, &B);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &A[i][j]);

    power(result, A, B);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }

    return 0;
}
