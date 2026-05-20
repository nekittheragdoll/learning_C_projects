#include <stdio.h>      // I want printf() and scanf()
#include <stdint.h>     // I want standardised integers across all OS's
#include <stdbool.h>    // I want a bool datatype
#include <stdlib.h>     // I want malloc() function

#include "primality.h"

bool isPrimeSimple(uint32_t candidate){
    if (candidate <= 1){    // if its 1 or less, then gtfo, wtf do you expect from me? >:(
        return false;
    }

    for (uint32_t i = 2; i * i <= candidate; i++){     // its enough to check only up to sqrt(candidate)
        if (candidate % i == 0){
            return false;               // e.g. 21/3=7 -> 21 % 3 = 0 -> 21 = 7 * 3 ; 21 is not prime
        }
    }

    // if no there no numbers, that can divide a candidate without remainder -> candidate is prime

    return true;
}

uint32_t *generatePrimes(uint32_t max){
    if (max < 2){
        return NULL;
    }

    uint32_t* num_arr = malloc(max * sizeof(uint32_t));
    uint32_t idx = 0;

    for (uint32_t i = 2; i <= max; i++){
        if (isPrimeSimple(i)){
            num_arr[idx] = i;
            idx++;
        }
    }

    num_arr[idx] = 0;
    idx++;

    uint32_t num_of_primes = idx;
    
    uint32_t *primes = realloc(num_arr, num_of_primes * sizeof(uint32_t));

    return primes;
}

int main(){
    uint32_t number = 100;   // DO NOT USE BIG NUMBERS FOR NOW

    uint32_t *list_of_primes = generatePrimes(number);

    printf("List of primes up to %d:\n", number);

    for (uint32_t cnt = 0; cnt <= number; cnt++){
        if(list_of_primes[cnt]==0){
            break;
        }
        printf("%d\n", list_of_primes[cnt]);
    }
    
    
    

}