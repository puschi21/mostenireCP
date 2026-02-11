#include <stdio.h>
#include <stdint.h>

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
