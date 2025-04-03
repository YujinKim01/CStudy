#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 100
#define MAX_LEN 11

int is_similar(char* base, char* other) {
    int count[26] = {0};

    for (int i = 0; base[i]; i++)
        count[base[i] - 'A']++;

    for (int i = 0; other[i]; i++)
        count[other[i] - 'A']--;

    int plus = 0, minus = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] == 1) plus++;
        else if (count[i] == -1) minus++;
        else if (abs(count[i]) > 1) return 0;
    }

    if ((plus == 0 && minus == 0) ||
        (plus == 1 && minus == 0) ||
        (plus == 0 && minus == 1) ||
        (plus == 1 && minus == 1)) return 1;

    return 0;
}

int main() {
    int n;
    char words[MAX_WORDS][MAX_LEN];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%s", words[i]);

    int count = 0;
    for (int i = 1; i < n; i++) {
        if (is_similar(words[0], words[i]))
            count++;
    }

    printf("%d\n", count);
    return 0;
}