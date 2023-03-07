#include <stdio.h>
#include <stdlib.h>

struct no {
    int valor;
    struct no *esquerda;
    struct no *direita;
};

struct no *novo_no(int valor) {
    struct no *no = malloc(sizeof(struct no));
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

struct no *inserir(struct no *no, int valor) {
    if (no == NULL) {
        return novo_no(valor);
    }
    if (valor < no->valor) {
        no->esquerda = inserir(no->esquerda, valor);
    } else if (valor > no->valor) {
        no->direita = inserir(no->direita, valor);
    }
    return no;
}

int buscar(struct no *no, int valor) {
    if (no == NULL) {
        return 0;
    }
    if (valor == no->valor) {
        return 1;
    } else if (valor < no->valor) {
        return buscar(no->esquerda, valor);
    } else {
        return buscar(no->direita, valor);
    }
}

int main(void) {
    struct no *raiz = NULL;
    raiz = inserir(raiz, 50);
    inserir(raiz, 30);
    inserir(raiz, 20);
    inserir(raiz, 40);
    inserir(raiz, 70);
    inserir(raiz, 60);
    inserir(raiz, 80);

    int valor_busca = 80;
    int resultado = buscar(raiz, valor_busca);
    if (resultado) {
        printf("Valor %d encontrado.\n", valor_busca);
    } else {
        printf("Valor %d não encontrado.\n", valor_busca);
    }
    return 0;
}
