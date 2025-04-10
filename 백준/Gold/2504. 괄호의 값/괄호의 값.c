#include <stdio.h>
#include <string.h>

char str[31];
int pos = 0;

int calc() {
    int sum = 0;
    while (str[pos] != '\0') {
        if (str[pos] == '(') {
            pos++;
            int inner = calc();
            if (str[pos] != ')') return -1;
            pos++;
            if (inner == 0) sum += 2;
            else if (inner > 0) sum += 2 * inner;
            else return -1;
        }
        else if (str[pos] == '[') {
            pos++;
            int inner = calc();
            if (str[pos] != ']') return -1;
            pos++;
            if (inner == 0) sum += 3;
            else if (inner > 0) sum += 3 * inner;
            else return -1;
        }
        else if (str[pos] == ')' || str[pos] == ']') {
            return sum;
        }
        else {
            return -1;
        }
    }
    return sum;
}

int main() {
    scanf("%s", str);
    int result = calc();

    if (str[pos] != '\0' || result == -1)
        printf("0\n");
    else
        printf("%d\n", result);
    return 0;
}