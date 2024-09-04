#include <stdio.h>
#include <stdlib.h>

typedef struct arv
{ 
    struct arv *esq;
    int item;
    struct arv *dir;
} *Arv;

// Fun��o que cria um n� de �rvore bin�ria e atribui os valores repassados como par�metros
Arv insereArv(Arv e, int N, Arv d) {
    Arv novoNo = (Arv)malloc(sizeof(struct arv));
    if (novoNo == NULL) {
        printf("Erro ao alocar mem�ria!\n");
        exit(1);
    }
    novoNo->esq = e;
    novoNo->item = N;
    novoNo->dir = d;
    return novoNo;
}

// Fun��o que recebe um endere�o da Raiz R e cria �rvore vazia
void criaArv(Arv *R) {
    *R = NULL;
}

// Percurso em Largura (n�o implementado no c�digo original)
void percursoLargura(Arv A) {
    // Esta fun��o pode ser implementada utilizando uma fila, mas n�o foi especificado como implement�-la no seu c�digo.
}

// Percurso Em Ordem
void percursoEmOrdem(Arv A) {
    if (A == NULL)
        return;
    percursoEmOrdem(A->esq);
    printf(" %i", A->item);
    percursoEmOrdem(A->dir);
}

// Percurso Pr�-Ordem
void percursoPreOrdem(Arv A) {
    if (A == NULL)
        return;
    printf(" %i", A->item);
    percursoPreOrdem(A->esq);
    percursoPreOrdem(A->dir);
}

// Percurso P�s-Ordem
void percursoPosOrdem(Arv A) {
    if (A == NULL)
        return;
    percursoPosOrdem(A->esq);
    percursoPosOrdem(A->dir);
    printf(" %i", A->item);
}

// Fun��o para destruir a �rvore
void destroiArvore(Arv *A) {
    if (*A == NULL)
        return;
    destroiArvore(&((*A)->esq));
    destroiArvore(&((*A)->dir));
    free(*A);
    *A = NULL;
}

int main() {
    Arv R;
    criaArv(&R);
    
    R = insereArv(insereArv(insereArv(NULL, 4, NULL), 2, insereArv(NULL, 5, NULL)),
                  1,
                  insereArv(NULL, 3, insereArv(NULL, 6, NULL)));
    
    printf("Percurso Em Ordem:\n");
    percursoEmOrdem(R);
    
    printf("\nPercurso Pre Ordem:\n");
    percursoPreOrdem(R);
    
    printf("\nPercurso Pos Ordem:\n");
    percursoPosOrdem(R);
    
    printf("\nDestruindo a arvore!\n");
    destroiArvore(&R);
    
    printf("Percurso Em Ordem ap�s destruir:\n");
    percursoEmOrdem(R);  // Deve imprimir nada, pois a �rvore foi destru�da
    
    return 0;
}

