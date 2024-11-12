/*
Faça um programa que receba 20 números e armazene os pares em uma lista
simplesmente encadeada e não ordenada e os ímpares em uma segunda lista
simplesmente encadeada e não ordenada. Posteriormente, o programa deve montar
uma terceira lista, duplamente encadeada e ordenada de forma crescente, com os
números das duas listas anteriores. Para finalizar, o programa deve mostrar todos os
números da terceira lista das seguintes formas:
a. Crescente.
b. Decrescente.
*/

#include <iostream>
using namespace std;

typedef struct Noh{
    int numero;
    Noh *proximo;
} Noh;

typedef struct Lista{
    Noh *inicio, *fim;
    int tamanho;
} Lista;

int menu()
{
    int opcao;

    do{
        cout << endl << "________ MENU DE OPCOES _________" << endl;
        cout << "| 1- Inserir numeros            |" << endl;
        cout << "| 2- Mostrar lista ímpar        |" << endl;
        cout << "| 3- Mostrar lista par          |" << endl;
        cout << "| 4- Mostrar lista crescente    |" << endl;
        cout << "| 5- Mostrar lista decrescente  |" << endl;
        cout << "| 6- Sair                       |" << endl;
        cout << "_________________________________" << endl;

        cout << "Digite sua escolha: ";
        cin >> opcao;

        if(opcao < 1 || opcao > 6)
            cout << "\tEscolha invalida!" << endl;
    }while(opcao < 1 || opcao > 6);

    return opcao;
}

void listaGeral(Lista *lst, int numero)
{
    Noh *novo = new Noh();
    novo ->numero = numero;

    if(eVazia(lst))
    {
        novo->proximo = NULL;
        lst->inicio = novo;
        lst->fim = novo;
    }
    else
    {
        novo->proximo = lst->inicio;
        lst->inicio = novo;
    }
    lst->tamanho++;
}

int main()
{
    Lista lista;

    lista.inicio = NULL;
    lista.fim = NULL;
    lista.tamanho = 0;

    int opcao, numero;

    do
    { 
        opcao = menu();

        switch (opcao)
        {
            case 1:
                cout << "Digite os numeros a serem inseridos ";
                cin >> numero;
                listaGeral(&lista, numero);
            break;

            case 2:
                cout << "Digite o numero a ser inserido no fim: ";
                cin >> numero;
                inserirFim(&lista, numero);
            break;

            case 3:
                cout << "Imprimindo lista...";
                imprime(&lista);
            break;

            case 4:
                cout << "Digite o numero a ser removido: ";
                cin >> numero;
                remover(&lista, numero);
            break;

            case 5:
                cout << "Esvaziando lista...";
                esvaziar(&lista);
            break;

            case 6:
                cout << "Saindo...";
            break;
        }

     }while (opcao != 6);

    return 0;
}
