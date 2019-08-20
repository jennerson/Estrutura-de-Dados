#include <stdio.h>
#include <math.h>

int main(){
	
	int i, soma;
	
	for(i=1;i<=64;i++){
		soma = soma + (i*2);
	}
	printf("Soma= %d", soma);
}
