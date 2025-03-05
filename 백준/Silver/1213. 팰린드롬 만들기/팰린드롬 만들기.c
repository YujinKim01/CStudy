#include <stdio.h>
#include <string.h>

#define MAX 50

char name[MAX + 1];  // 입력 문자열
int count[26];       // 알파벳 개수 카운트
char result[MAX + 1]; // 결과 저장

int main() {
    // 1. 입력 받기
    scanf("%s", name);
    int len = strlen(name);

    // 2. 알파벳 개수 카운트
    for (int i = 0; i < len; i++) {
        count[name[i] - 'A']++;
    }

    // 3. 홀수 개 문자 개수 확인 (팰린드롬 불가능 조건 체크)
    int odd_count = 0, mid_index = -1;
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 == 1) {
            odd_count++;
            mid_index = i;
        }
    }

    if (odd_count > 1) {
        printf("I'm Sorry Hansoo\n");
        return 0;
    }

    // 4. 팰린드롬 구성 (그리디 방식으로 작은 알파벳부터 배치)
    int left = 0, right = len - 1;
    for (int i = 0; i < 26; i++) {
        while (count[i] >= 2) {
            result[left++] = 'A' + i;
            result[right--] = 'A' + i;
            count[i] -= 2;
        }
    }

    // 5. 가운데 문자가 있으면 배치
    if (mid_index != -1) {
        result[left] = 'A' + mid_index;
    }

    // 6. 결과 출력
    result[len] = '\0';  // 문자열 끝 설정
    printf("%s\n", result);

    return 0;
}
