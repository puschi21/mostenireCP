#include <stdio.h>
#include <ctype.h>
#include <limits.h>

int threeInt(){
    int c, ok=1, cnt=0, lines=0, lastNum=INT_MIN, Num=0;
    while((c=getchar())!=EOF){
        if(isdigit(c)){
            while(isdigit(c)){
                Num=Num*10+c;
                c=getchar();
            }
            if(Num<=lastNum)
                ok=0;
            lastNum=Num;
            Num=0;
            cnt++;
        }
        if(c=='\n' && cnt>=3 && ok){
            lines++;
            cnt=0;
            lastNum=INT_MIN;
        }
    }
    return lines;
}

int main(){
    printf("%d", threeInt());
}