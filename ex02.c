#include <stdio.h>

int main(){
	float b,e;
	
	printf("Informe o valor da base: \n");
	scanf("%f",&b);
	
	printf("Informe o valor do expoente: \n");
	scanf("%f",&e);
	
	printf("Resultado = %.1f",pow(b,e));
	
}
