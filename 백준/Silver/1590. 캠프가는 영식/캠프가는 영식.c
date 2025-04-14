#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

int main(){
    int N, T;
    scanf("%d %d", &N, &T);
    
    int min_wait = INF;
    
    for (int i=0; i<N; i++){
        int S, I, C;
        scanf("%d %d %d",&S, &I, &C);
        
        for (int j=0;j<C; j++){
            int depart = S + j * I;
            if (depart >= T){
                int wait = depart - T;
                if (wait < min_wait){
                    min_wait = wait;
                }
                break;
            }
        }
    }
    if (min_wait == INF){
        printf("-1\n");
    }
    else {
        printf("%d\n", min_wait);
    }
    return 0;
}