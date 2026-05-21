#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrimeSimple(uint32_t candidate){
    if (candidate <= 1){
        return false;
    }

    for (uint32_t i = 2; i * i <= candidate; i++){
        if (candidate % i == 0){
            return false;
        }
    }
    return true;
}

uint32_t mod_pow(uint32_t base, uint32_t exp, uint32_t mod){
    uint32_t result = 1;

    base = base % mod;

    while (exp > 0){
        if (exp % 2 == 1){
            result = (result * base) % mod;
        }

        base = (base * base) % mod;
        exp = exp / 2; 
    }

    return result;
}

int main(){
    uint32_t p = 39103;
    uint32_t q = 19;    
    uint32_t g = 17464;

    uint32_t a = 17;
    uint32_t b = 11;

    uint32_t A = mod_pow(g,a,p);
    uint32_t B = mod_pow(g,b,p);

    printf("A side picks %i, calculates %i, and sends it to B\n", a, A);
    printf("B side picks %i, calculates %i, and sends it to A\n", b, B);

    printf("A---%i--->B\n", A);
    printf("A<---%i----B\n", B);

    printf("A side calculates secret key: %i\n", mod_pow(B,a,p));
    printf("B side calculates secret key: %i\n", mod_pow(A,b,p));
}