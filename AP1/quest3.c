#include <stdio.h>
#include <stdbool.h>

#define MASK 0x01

int contador_de_bits(bool w, unsigned int n) {
    int count = 0;
    while (n > 0) {
        count += n & MASK;
        n >>= MASK;
    }
    return count;
}

int main() {
    unsigned int n = 0;
    bool w;
    int a, num0, count;

    scanf("%d", &n);
    scanf("%d", &a);
    w = a;

    count = contador_de_bits(w, n);
    num0 = (32-count);
    
    if(w==1){
    	printf("%d\n", contador_de_bits(w, n));
	}else{
		printf("%d\n", num0);
	}
	
    return 0;
}
