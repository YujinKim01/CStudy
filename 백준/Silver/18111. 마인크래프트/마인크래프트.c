#include <stdio.h>

#define MAX_N 500
#define MAX_HEIGHT 256

int N, M, B;
int land[MAX_N][MAX_N];

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int main() {
    scanf("%d %d %d", &N, &M, &B);

    int min_height = MAX_HEIGHT, max_height = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &land[i][j]);
            min_height = min(min_height, land[i][j]);
            max_height = max(max_height, land[i][j]);
        }
    }

    int min_time = __INT_MAX__, best_height = 0;

    for (int target = min_height; target <= max_height; target++) {
        int remove_blocks = 0, add_blocks = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int diff = land[i][j] - target;
                if (diff > 0) {
                    remove_blocks += diff;
                } else {
                    add_blocks -= diff;
                }
            }
        }


        if (remove_blocks + B >= add_blocks) {
            int time = (remove_blocks * 2) + add_blocks; 

            if (time < min_time || (time == min_time && target > best_height)) {
                min_time = time;
                best_height = target;
            }
        }
    }

    printf("%d %d\n", min_time, best_height);
    return 0;
}