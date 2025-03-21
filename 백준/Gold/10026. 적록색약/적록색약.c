#include <stdio.h>
#include <string.h>

#define MAX 101

int N;
char grid[MAX][MAX];
int visited[MAX][MAX];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y, char color, int is_colorblind) {
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny]) {
            if (is_colorblind) { // 적록색약인 경우
                if ((color == 'R' || color == 'G') && (grid[nx][ny] == 'R' || grid[nx][ny] == 'G')) {
                    dfs(nx, ny, color, is_colorblind);
                } else if (grid[nx][ny] == color) {
                    dfs(nx, ny, color, is_colorblind);
                }
            } else { 
                if (grid[nx][ny] == color) {
                    dfs(nx, ny, color, is_colorblind);
                }
            }
        }
    }
}

int count_regions(int is_colorblind) {
    memset(visited, 0, sizeof(visited));
    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                dfs(i, j, grid[i][j], is_colorblind);
                count++;
            }
        }
    }
    return count;
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", grid[i]);
    }

    int normal_count = count_regions(0);
    int colorblind_count = count_regions(1);

    printf("%d %d\n", normal_count, colorblind_count);

    return 0;
}