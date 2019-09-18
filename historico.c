#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct alunos {
    char matricula[50];
    t_grade grade;
} t_aluno;

typedef struct turma {
    t_aluno alunos[60];
} t_turma;

typedef struct disciplinas {
    char nome[50];
} t_disciplina;

typedef struct grade {
    t_disciplina disciplina;
    int nota, n;
} t_grade;

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
	
}
