#include <stdio.h>
#include <stdlib.h>

#define MAX 1500000

typedef long long ll;

ll t;
int n, m;
int a[1001], b[1001];
ll sum_a[MAX], sum_b[MAX];
int size_a = 0, size_b = 0;

int cmp(const void* x, const void* y) {
    ll a = *(ll*)x;
    ll b = *(ll*)y;
    return (a > b) - (a < b);
}

int count_equal(ll* arr, int size, ll target) {
    int low = 0, high = size;
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] < target) low = mid + 1;
        else high = mid;
    }
    int lower = low;

    low = 0; high = size;
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] <= target) low = mid + 1;
        else high = mid;
    }
    int upper = low;

    return upper - lower;
}

int main() {
    scanf("%lld", &t);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);

    for (int i = 0; i < n; i++) {
        ll sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            sum_a[size_a++] = sum;
        }
    }

    for (int i = 0; i < m; i++) {
        ll sum = 0;
        for (int j = i; j < m; j++) {
            sum += b[j];
            sum_b[size_b++] = sum;
        }
    }

    qsort(sum_b, size_b, sizeof(ll), cmp);

    ll result = 0;
    for (int i = 0; i < size_a; i++) {
        ll need = t - sum_a[i];
        result += count_equal(sum_b, size_b, need);
    }

    printf("%lld\n", result);
    return 0;
}