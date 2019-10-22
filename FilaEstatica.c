#include <stdio.h>

#define MAX 10

typedef struct elementos {
    char nome[50];
    // Outros elementos
} t_elemento;

   // Estrutura da fila
typedef struct fila {
    t_elemento vetor[MAX]; 	//vet que armazena elem. da fila
    int inicio;
	int fim;
	int quant_element;		// quantidade de elementos da fila
} t_fila; 					// tipo fila

	// Criação da fila
t_fila criar(){
	
    t_fila fila;

    fila.inicio = 0;
    fila.fim = -1;
    fila.quant_element = 0;

    return fila;
}

	//Verificação
int isVazia (t_fila * fila){
	
    return (fila->quant_element == 0);
}

	//Verificação
int isCheia(t_fila * fila){
	
    return (fila->quant_element == MAX);
}

	//Inserindo na fila
int inserir (t_fila * fila, t_elemento valor){
	
    if (isCheia(fila))
        return 0;

    (fila->quant_element)++;
    fila->fim = (fila->fim + 1) % MAX;
    fila->vetor[fila->fim] = valor;
    return 1;
}

	//Removendo da fila
t_elemento remover(t_fila * fila){
	
    t_elemento valor = { "" } ;
    if (isVazia(fila))
        return valor; // Erro: fila vazia

    valor = fila->vetor[fila->inicio];
    fila->vetor[fila->inicio].nome[0] = '\0';// zera, opcional
    (fila->quant_element)--;
    fila->inicio = (fila->inicio + 1) % MAX;
    return valor;
}

	//Mostrando Fila
void exibir(t_fila * fila){
	
    int i;
    if (isVazia(fila)) {
        printf("Fila vazia\n");
        return;
    }

    printf("\nExibindo fila:\n");
    printf("inicio: %d\n", fila->inicio);
    printf("fim:    %d\n", fila->fim);
    for (i=0 ; i<MAX ; i++) {
        printf("%d::%s\n", i, fila->vetor[i].nome);
    }
}

void esvaziar(t_fila fila){
	
	int i;
    if (isVazia(fila)) {
        printf("Fila vazia\n");
        return;
    }
    for (i = fila->inicio; i != fila->fim + 1; i = (i + 1) % MAX){
    	fila->vetor[i].nome[0] = '\0';
	}

}






