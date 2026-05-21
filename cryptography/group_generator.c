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

int64_t *factorize(uint32_t number){

    int64_t *factors = malloc(sizeof(int64_t)*(number/2));
    uint32_t ptr = 0;

    for(uint32_t divisor = 2; divisor <= number; divisor++){
        if(number % divisor == 0){
            factors[ptr] = divisor;
            ptr++;
        }
        
        while(number % divisor == 0){
            number /= divisor;
        }
    }

    factors[ptr] = -1;

    int64_t *result = realloc(factors, sizeof(int64_t)*(ptr+1));

    return result;
}

void printFactors(uint32_t num){
    int64_t *primes = factorize(num);

    printf("[");
    for(uint32_t i = 0; true; i++){
        printf("%i, ", primes[i]);
        if (primes[i]<0){
            break;
        }
    }
    printf("]");
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

uint32_t MakeGenerator(uint32_t h, uint32_t pre, uint32_t q, uint32_t p){
    uint32_t g = mod_pow(h,(pre/q), p);
    return g;
}

int main(){

    uint32_t p = 39103;
    uint32_t pre = p-1;
    uint32_t q = 19;    
    uint32_t h = 27598;
    //uint32_t g = 17464;
    printf("Generator %d", MakeGenerator(h,pre,q,p));   // generator


}