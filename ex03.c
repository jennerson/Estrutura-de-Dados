#include <stdio.h>
#include <math.h>

int main(){
	
	int i ,prox=1;
	int ant=0, fib=0;
	fib= ant+prox;
	
	for (i=0;i<=14;i++){
		printf("%d, ",fib);
		fib = ant+prox;
		ant= prox;
		prox= fib;
	}
}
