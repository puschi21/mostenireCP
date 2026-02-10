#include <stdio.h>
#include <stdint.h>

// void altBits(uint16_t n){
//     uint16_t mask=1;
//     int i, ok=0;
//     for(i=0;i<16;i++){
//         int currentBit = (n >> i) & 1;
//         int nextBit = (n >> (i + 1)) & 1;
//         if(currentBit!=nextBit){
//             printf("%d-",i);
//             ok=1;
//         }
//         else if(ok==1){
//             ok=0;
//             printf("%d ",i);
//         }
//         mask=mask<<1;
//     }
// }

void altBits(uint16_t n) {
    int start = 0;

    for (int i = 0; i < 15; i++) {
        int current = (n >> i) & 1;
        int next = (n >> (i + 1)) & 1;

        if (current == next) {
            if (i > start) {
                printf("%d-%d\n", start, i);
            }
            start = i + 1;
        }        
        if (i == 14 && current != next) {
            printf("%d-%d\n", start, 15);
        }
    }
}

int main() {
    altBits(0xA505);
    return 0;
}