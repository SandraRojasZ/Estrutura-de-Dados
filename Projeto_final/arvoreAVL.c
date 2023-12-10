#include "projetoFinal.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


No* novoNo(DADOS *x) {
    No *novo = malloc(sizeof(No));

    if (novo != NULL) {
        novo->func.codigo = x->codigo;
        strcpy(novo->func.nome, x->nome);
        strcpy(novo->func.departamento, x->departamento);
        novo->func.idade = x->idade;
        strcpy(novo->func.empresa, x->empresa);
        novo->func.salario = x->salario;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        novo->altura = 0;
    } else {
        printf("\nERRO ao alocar!\n");
    }
    return novo;
}

int maior(int x, int y) {
    return (x > y) ? x : y;
}

int alt_no(No *no) {
    if (no == NULL)
        return -1;
    else
        return no->altura;
}

int fatorDeBalanceamento_NO(No *no) {
    return (alt_no(no->esquerdo) - alt_no(no->direito));
}

No* rotacaoL(No *r) {
    No *y, *f;

    y = r->direito;
    f = y->esquerdo;

    y->esquerdo = r;
    r->direito = f;

    r->altura = maior(alt_no(r->esquerdo), alt_no(r->direito)) + 1;
    y->altura = maior(alt_no(y->esquerdo), alt_no(y->direito)) + 1;

    return y;
}

No* rotacaoR(No *r) {
    No *y, *f;

    y = r->esquerdo;
    f = y->direito;

    y->direito = r;
    r->esquerdo = f;

    r->altura = maior(alt_no(r->esquerdo), alt_no(r->direito)) + 1;
    y->altura = maior(alt_no(y->esquerdo), alt_no(y->direito)) + 1;

    return y;
}

No* rotacaoLR(No *r) {
    r->esquerdo = rotacaoL(r->esquerdo);
    return rotacaoR(r);
}

No* rotacaoRL(No *r) {
    r->direito = rotacaoR(r->direito);
    return rotacaoL(r);
}

No* balancearr(No *raiz) {
    short fb = fatorDeBalanceamento_NO(raiz);

    if (fb < -1 && fatorDeBalanceamento_NO(raiz->direito) <= 0)
        raiz = rotacaoL(raiz);
    else if (fb > 1 && fatorDeBalanceamento_NO(raiz->esquerdo) >= 0)
        raiz = rotacaoR(raiz);
    else if (fb > 1 && fatorDeBalanceamento_NO(raiz->esquerdo) < 0)
        raiz = rotacaoLR(raiz);
    else if (fb < -1 && fatorDeBalanceamento_NO(raiz->direito) > 0)
        raiz = rotacaoRL(raiz);

    return raiz;
}

No* inserir(No *raiz, DADOS *x) {
    if (raiz == NULL)
        return novoNo(x);
    else {
        if (x->codigo < raiz->func.codigo)
            raiz->esquerdo = inserir(raiz->esquerdo, x);
        else if (x->codigo > raiz->func.codigo)
            raiz->direito = inserir(raiz->direito, x);
    }

    raiz->altura = maior(alt_no(raiz->esquerdo), alt_no(raiz->direito)) + 1;
    raiz = balancearr(raiz);

    return raiz;
}

void inserirElementosNaArvore(No **raiz, DADOS vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        *raiz = inserir(*raiz, &vetor[i]);
    }
}

void imprimirArvore(No *raiz) {
    if (raiz != NULL) {

        imprimirArvore(raiz->esquerdo);

        printf("\nCodigo: %d, Nome: %s, Idade: %d, Empresa: %s, Departamento: %s, Salario: %.2f\n",
               raiz->func.codigo, raiz->func.nome, raiz->func.idade, raiz->func.empresa,
               raiz->func.departamento, raiz->func.salario);

        imprimirArvore(raiz->direito);
    }
}
