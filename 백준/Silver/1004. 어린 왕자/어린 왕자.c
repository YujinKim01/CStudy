#include <stdio.h>

int is_in(int x, int y, int cx, int cy, int r){
    return (x-cx)*(x-cx) + (y-cy)*(y-cy) < r*r;
}

int main(){
    int t;
    scanf("%d", &t);
    
    while(t){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        int n, count=0;
        scanf("%d", &n);
        
        for (int i=0; i<n; i++){
            int cx, cy, r;
            scanf("%d %d %d", &cx, &cy, &r);
            
            int in1 = is_in(x1, y1, cx, cy, r);
            int in2 = is_in(x2, y2, cx, cy, r);
            
            if (in1 != in2){count++;}
        }
        printf("%d\n", count);
        t--;
    }
    return 0;
}