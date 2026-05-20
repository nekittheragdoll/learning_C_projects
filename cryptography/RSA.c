#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct 
{
    uint64_t PK;
    uint64_t SK;
    uint64_t n;
} RSAPar;



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

uint64_t GCD(uint64_t a, uint64_t b){
    while(b != 0){
        uint64_t temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

uint64_t mod_inverse(uint64_t a, uint64_t m){
    for (uint64_t i = 1; i < m; i++){
        if ((i * a) % m == 1){
            return i;
        }
    }

    return 0;
}

uint64_t mod_pow(uint64_t base, uint64_t exp, uint64_t mod){
    uint64_t result = 1;

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

RSAPar generateParameters(uint64_t p, uint64_t q, uint64_t PK){
    uint64_t n = p * q;
    uint64_t r = (p-1) * (q-1);

    RSAPar result = {0,0,0};

    if(GCD(PK, r) != 1 || PK >= r || PK <= 1){
        return result;
    }
    
    uint64_t SK = mod_inverse(PK, r);
    if (SK == 0){
        return result;
    }

    result.PK = PK;
    result.SK = SK;
    result.n = n;

    return result;
}

uint64_t E(uint64_t msg, uint64_t PK, uint64_t n){
    return mod_pow(msg, PK, n);
}

uint64_t D(uint64_t cphr, uint64_t SK, uint64_t n){
    return mod_pow(cphr, SK, n);
}




int main(){

    uint64_t p = 29;
    uint64_t q = 53;
    uint64_t PK = 17;

    RSAPar params = generateParameters(p, q, PK);

    uint64_t SK = params.SK;
    uint64_t n = params.n;

    uint64_t msg = 676;
    uint64_t ciphertext = E(msg, PK, n);
    uint64_t decrypted_msg = D(ciphertext, SK, n);

    printf("Original message is %d\n", msg);
    printf("Ciphertext is %d\n", ciphertext);
    printf("Decrypted message is %d\n", decrypted_msg);

}