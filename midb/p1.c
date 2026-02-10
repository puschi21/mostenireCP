#include <stdio.h>
#include <ctype.h>

void rld(){
    int c,nr,i;
    while((c=getchar()) != EOF){
        int aux=0;
        nr=getchar();
        if(isdigit(nr)){
            while(isdigit(nr)){
                aux=aux*10+(nr-'0');
                nr=getchar();
            }
            for(i=0;i<aux;i++){
                printf("%c",c);
            }
        }
        else{
            printf("%c",c);
        }
        ungetc(nr, stdin);
    }
}

int main(){
    rld();
    return 0;
}