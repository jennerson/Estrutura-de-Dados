#include <stdio.h>

#define MAX 10

typedef struct elementos {
    char nome[50];
    // Outros elementos
} t_elemento;

   // Estrutura da lista
typedef struct lista {
    t_elemento vetor[MAX]; 	//vet que armazena elem. da pilha
    int n; 					// posicao (indice) do ultimo elemento da lista
} t_lista; 					// tipo lista

void deslocaEsquerda(t_lista *lista, int pos){
	int i;
		
	for (i=pos; i< lista->n; i++){
		lista->vetor[i] = lista->vetor[i+1];
	}
}

int mostraNomes(t_lista *lista){
	int i;
		
	for (i=0; i<=lista->n; i++){
		printf(lista->vetor[i].nome);
	}	
}

int main(){
	t_lista minhaLista;
	int i;
	minhaLista.n = -1;
	
	for (i=0;i<=2;i++){
		
		scanf("%s", &minhaLista.vetor[i].nome);
		minhaLista.n = i;
	}
	
	mostraNomes(&minhaLista);
	
	return 0;
	
}
