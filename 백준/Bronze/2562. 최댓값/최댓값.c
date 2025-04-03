#include <stdio.h>
#include <stdlib.h>

int main(){
    int *arr = (int *)malloc(sizeof(int)*9);
    
    for (int i=0; i<9;i++){
        int n;
        scanf("%d", &n);
        arr[i] = n;
    }
    
    int max=arr[0], index=1;
    for (int i=1;i<9;i++){
        if (arr[i] > max){
            max = arr[i];
            index = i+1;
        }
    }
    printf("%d\n%d", max, index);
    free(arr);
    return 0;
}