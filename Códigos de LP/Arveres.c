#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int dado;
    struct node* esquerda;
    struct node* direita;
};

struct node* criarNo(int dado) {
    struct node* novoNo = (struct node*) malloc(sizeof(struct node));
    novoNo->dado = dado;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

void excluirSubarvore(struct node* node) {
    if (node == NULL) return;
    excluirSubarvore(node->esquerda);
    excluirSubarvore(node->direita);
    free(node);
}

void excluirNo(struct node* raiz, int dado) {
    if (raiz == NULL) return;
    if (raiz->esquerda != NULL && raiz->esquerda->dado == dado) {
        excluirSubarvore(raiz->esquerda);
        raiz->esquerda = NULL;
    }
    if (raiz->direita != NULL && raiz->direita->dado == dado) {
        excluirSubarvore(raiz->direita);
        raiz->direita = NULL;
    }
    excluirNo(raiz->esquerda, dado);
    excluirNo(raiz->direita, dado);
}

void imprimirArvore(struct node* node) {
    if (node == NULL) return;
    printf("%d\n", node->dado);
    imprimirArvore(node->esquerda);
    imprimirArvore(node->direita);
}

int posicao(struct node* node, int dado, int posicao) {
    if (node == NULL) return -1;
    int pos = posicaoEmPosOrdem(node->esquerda, dado, posicao);
    pos = posicaoEmPosOrdem(node->direita, dado, pos);
    if (node->dado == dado) return pos + 1;
    return pos;
}

int max(int a, int b) { return (a >= b) ? a : b; }

int alturaArvore(struct node *node) {
    if (node == NULL) return 0;
    return 1 + max(alturaArvore(node->esquerda), alturaArvore(node->direita));
}

int nivelDoNo(struct node *node, int dado, int nivel) {
    if (node == NULL) return 0;
    if (node->dado == dado) return nivel;
    int downLevel = nivelDoNo(node->esquerda, dado, nivel + 1);
    if (downLevel != 0) return downLevel;
    downLevel = nivelDoNo(node->direita, dado, nivel + 1);
    return downLevel;
}

int main() {
    struct node *raiz = novoNo(1);
    raiz->esquerda = novoNo(2);
    raiz->direita = novoNo(3);
    raiz->esquerda->esquerda = novoNo(4);
    raiz->esquerda->direita = novoNo(5);
    }
