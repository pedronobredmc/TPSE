#include <stdio.h>
#define MASK 0x01
// Define a macro para contar os bits definidos em um número
#define CONTADOR_DE_BITS(n) ({ \
    int count = 0; \
    while (n > 0) { \
        count += n & MASK; \
        n >>= MASK; \
    } \
    count; \
})

// Define a macro para imprimir o número binário
#define IMPRIME(n) ({ \
    for(int i=0; i<n;i++){ \
        printf("1"); \
    } for(int i=0; i<(8-n); i++){ \
        printf("0"); \
    }\
})

int main() {
    int n = 0;
    scanf("%d", &n);


    int count = CONTADOR_DE_BITS(n);
    IMPRIME(count);
    printf("\n");

    return 0;
}

