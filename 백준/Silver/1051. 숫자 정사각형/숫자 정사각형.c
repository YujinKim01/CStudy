#include <stdio.h>
#include <string.h>

char board[51][51];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%s", board[i]);
    }

    int max_size = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int size = 1; i + size < n && j + size < m; size++) {
                char corner = board[i][j];
                if (board[i][j + size] == corner &&
                    board[i + size][j] == corner &&
                    board[i + size][j + size] == corner) {
                    int area = (size + 1) * (size + 1);
                    if (area > max_size) max_size = area;
                }
            }
        }
    }

    printf("%d\n", max_size);
    return 0;
}