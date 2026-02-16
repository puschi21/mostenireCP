#include <stdio.h>
#include <stdint.h>

uint64_t build_mask(uint64_t lengths, uint8_t start_bit) {
    uint64_t result=0;
    uint8_t currentValue=start_bit;
    int aux, i;
    while(lengths && i<64){
        aux+=lengths%10;
        for(i=aux-lengths%10;i<aux && i<64;i++){
            result |= (currentValue<<i);
        }
        currentValue=!currentValue;
        lengths/=10;
    }
    return result;
}

int main(){
    printf("0x%lx\n",build_mask(90712,1));
}