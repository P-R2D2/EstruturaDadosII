#include <stdio.h>
#include <stdlib.h>

typedef struct arv
{ 
    struct arv *esq;
    int item;
    struct arv *dir;
} *Arv;

// Função que cria um nó de árvore binária e atribui os valores repassados como parâmetros
Arv insereArv(Arv e, int N, Arv d) {
    Arv novoNo = (Arv)malloc(sizeof(struct arv));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    novoNo->esq = e;
    novoNo->item = N;
    novoNo->dir = d;
    return novoNo;
}

// Função que recebe um endereço da Raiz R e cria árvore vazia
void criaArv(Arv *R) {
    *R = NULL;
}

// Percurso em Largura (não implementado no código original)
void percursoLargura(Arv A) {
    // Esta função pode ser implementada utilizando uma fila, mas não foi especificado como implementá-la no seu código.
}

// Percurso Em Ordem
void percursoEmOrdem(Arv A) {
    if (A == NULL)
        return;
    percursoEmOrdem(A->esq);
    printf(" %i", A->item);
    percursoEmOrdem(A->dir);
}

// Percurso Pré-Ordem
void percursoPreOrdem(Arv A) {
    if (A == NULL)
        return;
    printf(" %i", A->item);
    percursoPreOrdem(A->esq);
    percursoPreOrdem(A->dir);
}

// Percurso Pós-Ordem
void percursoPosOrdem(Arv A) {
    if (A == NULL)
        return;
    percursoPosOrdem(A->esq);
    percursoPosOrdem(A->dir);
    printf(" %i", A->item);
}

// Função para destruir a árvore
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
    
    printf("Percurso Em Ordem após destruir:\n");
    percursoEmOrdem(R);  // Deve imprimir nada, pois a árvore foi destruída
    
    return 0;
}

