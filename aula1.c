#include <stdlib.h>
#include <stdio.h>

typedef struct reg{
	float comprimento, largura, area;
	char *nome;
} registro;

typedef struct casa{
	registro casa[50];
	float area_total;
}casa;

int main(){
	return 0;
}
