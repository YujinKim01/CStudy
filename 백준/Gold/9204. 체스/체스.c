#include <stdio.h>

int col(char c){
    return c - 'A' + 1;
}

int row(int r){
    return r;
}

int same_color(int x1, int y1, int x2, int y2){
    return (x1 + y1) % 2 == (x2 + y2) % 2;
}

int same_diag(int x1, int y1, int x2, int y2){
    return (x1 - y1 == x2 - y2) || (x1 + y1 == x2 + y2);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char c1, c2;
        int r1, r2;
        scanf(" %c %d %c %d", &c1, &r1, &c2, &r2);

        int x1 = col(c1), y1 = row(r1);
        int x2 = col(c2), y2 = row(r2);

        if (!same_color(x1, y1, x2, y2)) {
            printf("Impossible\n");
        } else if (x1 == x2 && y1 == y2) {
            printf("0 %c %d\n", c1, r1);
        } else if (same_diag(x1, y1, x2, y2)) {
            printf("1 %c %d %c %d\n", c1, r1, c2, r2);
        } else {
            int found = 0;
            for (int i = 1; i <= 8 && !found; i++) {
                for (int j = 1; j <= 8; j++) {
                    if (same_diag(x1, y1, i, j) && same_diag(x2, y2, i, j)) {
                        char mid_c = i + 'A' - 1;
                        int mid_r = j;
                        printf("2 %c %d %c %d %c %d\n", c1, r1, mid_c, mid_r, c2, r2);
                        found = 1;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}