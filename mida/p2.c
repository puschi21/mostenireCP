#include <stdio.h>
#include <stdint.h>

void shiftByN(uint16_t hex, int n){
    uint16_t aux=hex;
    printf("Original number: 0X%X\n", hex);
    do{
        uint16_t mask=1<<15;
        int i;
        aux=((aux<<n) | (aux>>(16-n)));
        printf("0x%0X ", aux);
        for(i=0;i<16;i++){
            if(aux&mask)
                printf("1");
            else
                printf("0");
            mask=mask>>1;
        }
        printf("\n");
    }while(aux!=hex);
}

int main(){
    shiftByN(0x1a2b,2);
    return 0;
}