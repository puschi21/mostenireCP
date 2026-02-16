#include <stdio.h>
#include <ctype.h>

void validAlpha(){
    int c, cnt=0, maxc=0, maxi, i=1;
    while((c=getchar())!=EOF){
        int ok=1;
        while(c!=',' && c!='\n' && c!=EOF){
            if(!isalpha(c))
                ok=0;
            c=getchar();
        }
        if(ok)
            cnt++;
        if(c=='\n')
        {
            if(maxc<cnt){
                maxc=cnt;
                maxi=i;
            }
            printf("%d\n", cnt);
            cnt=0;
            i++;
        }
    }
    printf("The line with the most fields: %d", maxi);
} 

int main(){
    validAlpha();
}