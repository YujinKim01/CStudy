#include <stdio.h>
#include <stdlib.h>

#define MAX_N 15

int N;
int col[MAX_N];
int solution_count = 0;

int is_valid(int row, int column) {
    for (int i = 0; i < row; i++) {
        // 같은 열 or 대각선에 퀸이 존재하는지 검사
        if (col[i] == column || abs(col[i] - column) == abs(i - row)) {
            return 0;
        }
    }
    return 1;
}

void sol(int row) {
    if (row == N) {
        solution_count++;
        return;
    }

    for (int j = 0; j < N; j++) {
        if (is_valid(row, j)) {
            col[row] = j;  // 퀸 배치
            sol(row + 1);
        }
    }
}

int main() {
    scanf("%d", &N);
    sol(0);
    printf("%d\n", solution_count);
    return 0;
}