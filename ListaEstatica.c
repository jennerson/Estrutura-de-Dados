#include <stdio.h>
#include <string.h>
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

t_lista criar() {
    t_lista lista;

    lista.n = -1;

    return lista;
}

int isVazia(t_lista * lista) {
    return (lista->n == -1);
}

int isCheia(t_lista * lista) {
    return (lista->n == MAX-1);
}

int getTamanho(t_lista * lista) {
    return lista->n + 1;
}

t_elemento * getElemento(t_lista * lista, int pos) {
    // verifica se pos eh valida
    if ( (pos > lista->n) || (pos < 0) )
        return 0;

    return &(lista->vetor[pos]);
}

int getPosicao(t_lista * lista, t_elemento dado) {
    int i;
    for (i=0; i<=lista->n; i++)
        if (compara(lista->vetor[i], dado)==0)
            return i;

    return -1;
}

int compara(t_elemento dado1, t_elemento dado2) {
    return strcmp(dado1.nome, dado2.nome);
}

int deslocaDireita(t_lista * lista, int pos) {
    int i;

    for (i=lista->n + 1; i>pos; i--)
        lista->vetor[i] = lista->vetor[i-1];

    return 1;
}

int inserir (t_lista * lista, int pos, t_elemento dado) {
    if ( isCheia(lista) || (pos > lista->n + 1) || (pos < 0) ){
		printf("Impossível inserir!");
        return 0;
	}
    deslocaDireita(lista, pos);
    lista->vetor[pos] = dado;
    (lista->n)++;
    return 1;
}

void deslocaEsquerda(t_lista *lista, int pos){
	int i;
		
	for (i=pos; i< lista->n; i++){
		lista->vetor[i] = lista->vetor[i+1];
	}
}

int remover (t_lista *lista, int pos) {
    if ( (pos > lista->n) || (pos < 0) )
        return 0;

    deslocaEsquerda(lista, pos);

    (lista->n)--;
    return 1;
}

int mostraNomes(t_lista *lista){
	int i;
		
	for (i=0; i<=lista->n; i++){
		printf("%d - [%s]\n",i,lista->vetor[i].nome);
	}	
}

int main(){
	t_lista minhaLista = criar();
	int i;
	t_elemento elemento;
	t_elemento *pElemento;
	
	for (i=0;i<=2;i++){				//PREENCHENDO A LISTA
		printf("\nInserir nome: ");
		scanf("%s", &elemento.nome);
		inserir(&minhaLista,i,elemento);
	}
	
	mostraNomes(&minhaLista);		//MOSTRANDO CONTEÚDO
	
	printf("\nBuscar nome: ");		//BUSCANDO CONTEÚDO
	scanf("%s", &elemento.nome);
	i = getPosicao(&minhaLista,elemento);
	if((pElemento = getElemento(&minhaLista,i)) == NULL){
		printf("NAO ENCONTRADO!");
	}else{
		printf("Nome [%s] encontrado na posicao [%d]", pElemento->nome,i);
	}
	
	printf("\nRemover o nome: ");		//REMOVENDO CONTEÚDO
	scanf("%s", &elemento.nome);
	if (i = getPosicao(&minhaLista,elemento)== -1){
		printf("NAO ENCONTRADO!");
	}else{
		remover(&minhaLista, i);
		printf("NOVA LISTA: \n");
		mostraNomes(&minhaLista);
	}
	return 0;
}

