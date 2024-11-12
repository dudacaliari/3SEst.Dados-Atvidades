#include <iostream>
using namespace std;

// Estrutura que representa um nó da lista simplesmente encadeada
struct No {
    int valor;
    No* proximo;
};

// Estrutura que representa um nó da lista duplamente encadeada
struct NoDuplo {
    int valor;
    NoDuplo* proximo;
    NoDuplo* anterior;
};

// Função que insere um valor no final da lista simplesmente encadeada
void inserirNo(No*& inicio, int valor) {
    No* novoNo = new No;
    novoNo->valor = valor;
    novoNo->proximo = NULL;

    if (inicio == NULL) {
        inicio = novoNo;
    }
    else {
        No* atual = inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
    }
}

// Função que insere um valor em ordem na lista duplamente encadeada
void inserirNoDuploOrdenado(NoDuplo*& inicio, int valor) {
    NoDuplo* novoNo = new NoDuplo;
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    novoNo->anterior = NULL;

    if (inicio == NULL) {
        inicio = novoNo;
    }
    else if (valor < inicio->valor) {
        novoNo->proximo = inicio;
        inicio->anterior = novoNo;
        inicio = novoNo;
    }
    else {
        NoDuplo* atual = inicio;
        while (atual->proximo != NULL && valor > atual->proximo->valor) {
            atual = atual->proximo;
        }
        novoNo->proximo = atual->proximo;
        novoNo->anterior = atual;
        if (atual->proximo != NULL) {
            atual->proximo->anterior = novoNo;
        }
        atual->proximo = novoNo;
    }
}

int main() {
    No* listaPares = NULL;
    No* listaImpares = NULL;

    for (int i = 0; i < 20; i++) {
        int valor;
        cout << "Digite um numero: ";
        cin >> valor;

        if (valor % 2 == 0) {
            inserirNo(listaPares, valor);
        }
        else {
            inserirNo(listaImpares, valor);
        }
    }

    NoDuplo* listaOrdenada = NULL;

    // Adiciona os valores da lista de pares na lista ordenada
    No* atual = listaPares;
    while (atual != NULL) {
        inserirNoDuploOrdenado(listaOrdenada, atual->valor);
        atual = atual->proximo;
    }

    // Adiciona os valores da lista de ímpares na lista ordenada
    atual = listaImpares;
    while (atual != NULL) {
        inserirNoDuploOrdenado(listaOrdenada, atual->valor);
        atual = atual->proximo;
    }

    // Imprime a lista ordenada de forma crescente
    cout << "Lista ordenada crescente: ";
    atual = listaOrdenada;
    while (atual != NULL) {
        cout << atual->valor << " ";
        atual = atual->proximo;
    }
    cout << endl;

    // Imprime a lista ordenada de forma decrescente
    cout << "Lista ordenada decrescente: ";
    atual = lista