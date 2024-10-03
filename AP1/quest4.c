#include <stdio.h>
#include <stdbool.h>

#define MASK(i,j) (((1<<(j-i + 1)) -1) << i)

int setBits(bool w, unsigned int i, unsigned int j, unsigned int value) {

  	if(w==1){
  		value |= MASK(i, j);
  		return value;
  	}else{
  		value &= ~MASK(i, j);
  		return value;
  	}
}

int main() {
	unsigned int w, value, i, j;
	scanf("%d %d %d %d", &w, &i, &j, &value);
	printf("%d\n", setBits(w, i, j, value));
	
}
