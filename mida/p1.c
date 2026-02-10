#include <stdio.h>
#include <ctype.h>

void rle(){
    int c, cnt=1, lastchar=getchar();
    if (lastchar == EOF) {
        return;
    }
    while((c=getchar()) != EOF){
        if(c == lastchar){
            lastchar=c;
            cnt++;
        }
        else{
            if(cnt==1)
                printf("%c",lastchar);    
            else
                printf("%c%d",lastchar,cnt);
            cnt=1;
            lastchar=c;
        }
    }
    printf("%c%d",lastchar,cnt);
}

int main(){
    rle();
    return 0;
}