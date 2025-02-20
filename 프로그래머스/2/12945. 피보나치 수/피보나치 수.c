#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int prev = 0;
    int curr = 1;
    int temp;
    
    for (int i = 2; i <= n; i++) {
        temp = (prev + curr) % 1234567;
        prev = curr;
        curr = temp;
    }
    
    return curr;
}
