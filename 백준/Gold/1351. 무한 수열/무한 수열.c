#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMO 1000000

typedef long long ll;

typedef struct {
    ll key;
    ll value;
} entry;

entry memo[MAX_MEMO];
int memo_size = 0;

ll P, Q;

int cmp(const void* a, const void* b) {
    ll x = ((entry*)a)->key;
    ll y = ((entry*)b)->key;
    return (x > y) - (x < y);
}

ll find(ll n) {
    entry temp = {n, 0};
    entry* res = bsearch(&temp, memo, memo_size, sizeof(entry), cmp);
    if (res) return res->value;
    return -1;
}

void insert(ll n, ll val) {
    if (memo_size >= MAX_MEMO) return;
    memo[memo_size].key = n;
    memo[memo_size].value = val;
    memo_size++;
}

ll get(ll n) {
    if (n == 0) return 1;

    ll cached = find(n);
    if (cached != -1) return cached;

    ll val = get(n / P) + get(n / Q);
    insert(n, val);
    return val;
}

int main() {
    ll N;
    scanf("%lld %lld %lld", &N, &P, &Q);

    ll result = get(N);

    qsort(memo, memo_size, sizeof(entry), cmp);

    printf("%lld\n", result);
    return 0;
}