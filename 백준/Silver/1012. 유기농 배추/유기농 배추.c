#include <stdio.h>
#include <string.h>

#define MAX 50

int T, M, N, K;
int field[MAX][MAX];
int visited[MAX][MAX];
int dx[] = {0, 0, 1, -1};  // 상하좌우 이동
int dy[] = {1, -1, 0, 0};

// DFS 탐색
void dfs(int x, int y) {
    visited[x][y] = 1;  // 방문 처리

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
            if (field[nx][ny] == 1 && !visited[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d %d", &M, &N, &K);

        memset(field, 0, sizeof(field));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < K; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            field[x][y] = 1;
        }

        int worm_count = 0;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (field[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j);
                    worm_count++;
                }
            }
        }

        printf("%d\n", worm_count);
    }

    return 0;
}