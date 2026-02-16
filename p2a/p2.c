#include <stdio.h>
#include <stdint.h>

uint64_t minValue(uint64_t n, uint8_t k){
    if(k==0)
        return n;
    uint64_t mask=(1<<k)-1, minv=n^mask;
    int i;
    for(i=1;i<64;i++){
        if((n^(mask<<i))<minv)
            minv=n^(mask<<i);
    }
    return minv;
}

int main(){
    printf("%lx",minValue(0x6,1));
}