#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 8

typedef struct carro {
    char placa[6];
} t_carro;

typedef struct pilha {
    t_carro carros[MAX];
    int topo;
} t_pilha;

t_pilha criar() {
    t_pilha pilha;

    pilha.topo = -1;

    return pilha;
}

int isVazia(t_pilha * pilha) {
    return (pilha->topo == -1);
}

int isCheia(t_pilha * pilha) {
    return (pilha->topo == MAX-1);
}

t_carro getTopo(t_pilha * pilha){
    t_carro vazio = { "" } ;

    if (isVazia(pilha)){
    	printf("Pilha vazia !!!");
        return vazio;
    }else{
        return pilha->carros[pilha->topo];
	}
}

int push(t_pilha *pilha, t_carro carro){
    if (isCheia(pilha)){
    	printf("Pilha cheia !!!");
        return 0;
	}
    pilha->carros[++pilha->topo] = carro;

    return 1;
}

t_carro pop(t_pilha * pilha){
    t_carro vazio = { "" };

    if (isVazia(pilha)){
    	printf("Pilha vazia !!!");
        return vazio; 
    }else{
        return pilha->carros[pilha->topo--];
    }
}

void entra5(t_pilha pilha){
	int i=0;
	t_carro carro;
	
	for(i=0; i<5; i++){
		printf("Informe a placa do carro: \n");
		scanf("%s",carro.placa);
		push(&pilha, carro);
	}
}

void sai3(t_pilha pilha){
	int i=0;
	
	for(i=0;i<3;i++){
		printf("Saida de carro, placa: %s\n",pilha.carros[pilha.topo].placa);
		pop(&pilha);
	}
}

int main (){
	
	int i= 0;
	t_pilha pilha;
	
	entra5(pilha); //Letra a)
	
	printf("Quinto carro: %s\n", pilha.carros[4].placa);	//Letra b)
	
	sai3(pilha);	//Letra c)
			
	printf("Restaram %d carros\n",getTopo(&pilha));  //Letra d)
	
	return 0;
}

