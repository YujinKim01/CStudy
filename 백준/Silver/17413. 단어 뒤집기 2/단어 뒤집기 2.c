#include <stdio.h>
#include <string.h>

#define N 100001

void prt_rev(char *s, int start, int end) {
    for (int i=end-1; i>=start; i--){
        printf("%c",s[i]);
    }
}

int main(){
    char s[N];
    fgets(s, N, stdin);
    int len = strlen(s);
    
    if (s[len-1] == '\n'){
        s[len-1] = '\0'; len--;
    }
    
    int in_tag = 0;
    int start = -1;
    
    for (int i=0; i<len; i++){
        if (s[i] == '<'){
            if (start != -1){
                prt_rev(s, start, i);
                start = -1;
            }            
            in_tag = 1;
            printf("<");
        }
        else if (s[i] == '>'){
            in_tag = 0;
            printf(">");
        }
        else if (in_tag){
            printf("%c", s[i]);
        }
        else{
            if (s[i] == ' '){
                if (start != -1){
                    prt_rev(s, start, i);
                    start = -1;
                }
                printf(" ");
            }
            else{
                if (start == -1){
                    start = i;                 
                }
                if (i == len-1){
                    prt_rev(s, start, len);
                }
            }
        }
    }
    return 0;
}