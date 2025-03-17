#include <stdio.h>

#define MAX_N 50
#define MAX_M 50

char board[MAX_N][MAX_M];
int N, M;

int count_repaint(int x, int y, char first_color) {
    int count = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char expected_color = ((i + j) % 2 == 0) ? first_color : (first_color == 'W' ? 'B' : 'W');
            if (board[x + i][y + j] != expected_color) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%s", board[i]);
    }

    int min_repaint = 64;

    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            int repaintW = count_repaint(i, j, 'W');
            int repaintB = count_repaint(i, j, 'B');
            int min_current = (repaintW < repaintB) ? repaintW : repaintB;
            if (min_current < min_repaint) {
                min_repaint = min_current;
            }
        }
    }

    printf("%d\n", min_repaint);
    return 0;
}