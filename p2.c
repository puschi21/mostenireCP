#include <stdio.h>

int symmNibbles(unsigned n){
    int ok=1, i;
    for(i=0;i<4 && ok;i++){
        unsigned right=(n>>(i*4))&0xf;
        unsigned left=(n>>((7-i)*4))&0xf;
        printf("%x %x\n",left,right);
        if(left!=right)
            ok=0;
    }
    if(ok)
        return 1;
    return 0;
}

int main(){
    printf("The answer is: %d", symmNibbles(0x16ADDA61));
}