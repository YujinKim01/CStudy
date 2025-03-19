#include <stdio.h>

#define MAX_N 1000

int T, N;
int arr[MAX_N + 1];
int visited[MAX_N + 1];

// DFS 탐색
void dfs(int node) {
    visited[node] = 1;
    int next = arr[node];

    if (!visited[next]) {
        dfs(next);
    }
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &N);

        for (int i = 1; i <= N; i++) {
            scanf("%d", &arr[i]);}

        for (int i = 1; i <= N; i++) {
            visited[i] = 0;}

        int cycle_count = 0;

        // 모든 노드를 방문하며 DFS 탐색
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                dfs(i);
                cycle_count++;
            }
        }

        printf("%d\n", cycle_count);
    }

    return 0;
}