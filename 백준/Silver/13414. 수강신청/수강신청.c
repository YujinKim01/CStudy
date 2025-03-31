#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_L 500001
#define MAX_ID_LEN 9
#define HASH_SIZE 100003

typedef struct node {
    char id[MAX_ID_LEN];
    int last_pos;
    struct node* next;
} node;

char wait_list[MAX_L][MAX_ID_LEN];
int is_used[MAX_L];
node* hash_table[HASH_SIZE];

// 해시 함수 (djb2 방식)
unsigned int hash(const char* str) {
    unsigned int h = 5381;
    while (*str) {
        h = ((h << 5) + h) + (*str);
        str++;
    }
    return h % HASH_SIZE;
}

// 해시 테이블에서 학번을 찾거나 추가
node* find_or_insert(const char* id, int tail) {
    unsigned int h = hash(id);
    node* curr = hash_table[h];

    while (curr) {
        if (strcmp(curr->id, id) == 0) {
            return curr; // 이미 존재하는 학번
        }
        curr = curr->next;
    }

    // 새 노드 생성
    node* new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->id, id);
    new_node->last_pos = tail;
    new_node->next = hash_table[h];
    hash_table[h] = new_node;

    return NULL; // 새로 추가했음을 의미
}

int main() {
    int k, l;
    scanf("%d %d", &k, &l);

    int tail = 0;

    for (int i = 0; i < l; i++) {
        char id[MAX_ID_LEN];
        scanf("%s", id);

        node* existing = find_or_insert(id, tail);
        if (existing) {
            is_used[existing->last_pos] = 0; // 기존 위치 무효화
            existing->last_pos = tail;
        }

        strcpy(wait_list[tail], id);
        is_used[tail] = 1;
        tail++;
    }

    int printed = 0;
    for (int i = 0; i < tail && printed < k; i++) {
        if (is_used[i]) {
            printf("%s\n", wait_list[i]);
            printed++;
        }
    }

    return 0;
}