#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

uint8_t lfsr8_next(uint8_t *state){
    uint8_t bit;

    bit = (
        (*state >> 0) ^
        (*state >> 1) ^
        (*state >> 3) ^
        (*state >> 7)
    ) & 1u;

    *state = (*state >> 1) | (bit << 7);

    //^ -- XOR
    //<< left bit shift
}

uint32_t lfsr32_next(uint32_t *state){
    uint8_t bit;

    bit = (
        (*state >> 0) ^
        (*state >> 1) ^
        (*state >> 21) ^
        (*state >> 31)
    ) & 1u;

    *state = (*state >> 1) | (bit << 31);

    //^ -- XOR
    //<< left bit shift
}

int main(){
    uint32_t seed = 1;
    uint8_t seed8 = 1;
    for (uint32_t i = 0; i < 32; i++){
        lfsr32_next(&seed);
        printf("%u\n", seed);
    }
    for (uint32_t i = 0; i < 512; i++){
        lfsr8_next(&seed8);
        printf("%u\n", seed8);
    }
}