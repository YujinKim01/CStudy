#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_C 15

int L, C;
char chars[MAX_C];
char password[MAX_C];

int is_vowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int compare_chars(const void *a, const void *b) {
    return (*(const char *)a - *(const char *)b);
}

void backtrack(int index, int depth, int vowels, int consonants) {
    if (depth == L) {
        if (vowels >= 1 && consonants >= 2) {
            password[depth] = '\0';
            printf("%s\n", password);
        }
        return;
    }

    for (int i = index; i < C; i++) {
        password[depth] = chars[i];

        if (is_vowel(chars[i])) {
            backtrack(i + 1, depth + 1, vowels + 1, consonants);
        } else {
            backtrack(i + 1, depth + 1, vowels, consonants + 1);
        }
    }
}

int main() {
    scanf("%d %d", &L, &C);
    for (int i = 0; i < C; i++) {
        scanf(" %c", &chars[i]);
    }

    qsort(chars, C, sizeof(char), compare_chars);

    backtrack(0, 0, 0, 0);

    return 0;
}