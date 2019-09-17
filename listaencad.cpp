#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tipo base dos elementos da lista 
typedef struct elementos {
    char nome[50];
    // Outros elementos
} t_elemento;

// Estrutura lista
typedef struct no {
    t_elemento dado;  // elemento contendo os dados
    struct no * prox; // ponteiro para o proximo elemento
} t_no; // tipo da estrutura

// define t_lista como sendo um outro nome para "t_no *"
typedef t_no * t_lista;

/**
 * Cria um novo no, aloca a sua regiao de memoria,
 * inicializa o ponteiro prox, e retorna o ponteiro o no criado.
 * 
 * @return No alocada e inicializada
 */
t_no * criaNo() {
    t_no * no = (t_no*) malloc(sizeof(t_no));

    if (no)
        no->prox = NULL;

    return no;
}

/**
 * Verifica se a lista esta vazia ou nao. Isto so acontece quando ela eh nula
 * 
 * @param lista ponteiro para a lista
 *
 * @return Verdadeiro (1) se a lista estiver vazia, ou falso (0) caso contrario.
 */
int isVazia(t_lista lista) {
    return (lista == NULL);
}

/**
 * Percorre toda a lista, e obtem o tamanho atual.
 * 
 * @param lista ponteiro para a lista.
 *
 * @return o quantidade de elementos que estao na lista.
 */
int getTamanho(t_lista lista) {
    int n = 0;
    while (lista != NULL) {
        lista = lista->prox;
        n++;
    }
    return n;
}

/**
 * Insere um elemento (dado) em determinada posicao da lista.
 * 
 * @param lista ponteiro para a lista
 * @param pos   posicao que o elemento que sera inserido ficara.
 * @param dado  elemento a ser inserido
 *
 * @return Falso(0) se a posição for invalida ou se a lista estiver cheia, caso contrario, retorna Verdadeiro(1).
 */
 /**
 * Percorre toda a lista ate chegar na posicao desejada, em seguida retorna
 * o endereco do no atual.
 * 
 * @param lista ponteiro para a lista
 * @param pos   posicao do no desejado
 * @see getElemento()
 *
 * @return ponteiro para o elemento desejado, caso a posicao seja invalida retorna 0.
 */
t_no * getNo(t_lista lista, int pos) {
    // Retorna 0 se posicao invalida. Do contrario, retorna o elemento
    int n = 0;

    if (pos<0)
        return 0; // erro: posicao invalida

    while (lista != NULL) {
        if (n==pos)
            return lista;
        lista = lista->prox;
        n++;
    }
    return 0; // erro: posicao invalida
}

int inserir(t_lista *lista, int pos, t_elemento dado) {
    t_no * p, * novo;
    // inserção na primeira posicao ou em lista vazia
    if (pos == 0) {
        novo = criaNo();
        if (novo == NULL)
            return 0; // erro: memoria insuficiente
        novo->dado = dado;
        novo->prox = *lista;
        *lista = novo;
        return 1;
    }
    // insercao apos a primeira posicao em lista nao vazia
    p = getNo(*lista, pos-1);
    if (p == NULL)
         return 0; // erro: posicao invalida 
    novo = criaNo();
    if (novo == NULL)
        return 0; // erro: memoria insuficiente
    novo->dado = dado;
    novo->prox = p->prox;
    p->prox = novo;

    return 1;
}

int remover(t_lista *lista, int pos) {
    t_no *anterior, *p;
    if (isVazia(*lista)) return 0; // erro: lista vazia
    if (pos<0) return 0; // erro: posicao invalida

    // remocao da primeira posicao em lista nao vazia
    if (pos == 0) {
        p = *lista;
        *lista = p->prox;
    } else { // remocao em qualquer posicao
        anterior = getNo(*lista, pos-1);
        if (anterior == NULL)
            return 0; // erro: posicao invalida
        p = anterior->prox;
        if (p == NULL)
            return 0; // erro: posicao invalida
        anterior->prox = p->prox;
    }
    free(p);
    return 1;
}


int main(){
				//Variaveis
	int i=0;
	t_elemento dado;
	t_lista lista;
	t_lista aux;
				//Criar Lista			
				
				//Alimentar Lista
	for(i=0;i<3;i++){
		printf("Informe um nome:\n");
		scanf("%s",&dado.nome);
		if(!inserir(&lista, i, dado)){
			printf("Erro!\n");
		}
	}			
				
				//Mostrar Lista
	aux = lista;
	while(true){
		printf("%s");
	}			
				
}
