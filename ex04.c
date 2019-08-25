#include <stdio.h>
#include <math.h>

int main(){
	
	int i, soma=1, ant=0, graos=1;

	for(i=0;i<64;i++){
		ant = graos * 2;
		graos = graos * 2;
		soma = soma + graos;
	}
	printf("Soma= %d", soma);
}
