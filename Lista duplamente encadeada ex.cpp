#include <iostream>

using namespace std;

typedef struct Noh{
    int numero;
    Noh *proximo;
    Noh *anterior;
} Noh;

typedef struct Lista{
    Noh *inicio, *fim;
    int tamanho;
} Lista;

int menu()
{
    int opcao;

    do{
        cout << endl << "MENU DE OPCOES" << endl;
        cout << "1- Inserir no inicio da lista" << endl;
        cout << "2- Inserir no fim da lista" << endl;
        cout << "3- Imprimir lista do inicio ao fim" << endl;
        cout << "4- Imprimir lista do fim ao inicio" << endl;
        cout << "5- Remover da lista" << endl;
        cout << "6- Esvaziar a lista" << endl;
        cout << "7- Sair" << endl;

        cout << "Digite sua escolha: ";
        cin >> opcao;

        if(opcao < 1 || opcao > 7)
            cout << "\tEscolha invalida!" << endl;
    }while(opcao < 1 || opcao > 7);

    return opcao;
}

bool eVazia(Lista *lst)
{
    if(lst->inicio == NULL)
        return true;
    return false;
}

void inserirInicio(Lista *lst, int numero)
{
    Noh *novo = new Noh();
    novo ->numero = numero;

    if(eVazia(lst))
    {
        novo->proximo = NULL;
        novo->anterior = NULL;
        lst->inicio = novo;
        lst->fim = novo;
    }
    else
    {
        novo->proximo = lst->inicio;
        novo->anterior = NULL;
        lst->inicio->anterior = novo;
        lst->inicio = novo;
    }
    lst->tamanho++; 
}

void inserirFim(Lista *lst, int numero)
{
    Noh *novo = new Noh();
    novo ->numero = numero;

    if(eVazia(lst))
    {
        novo->proximo = NULL;
        novo->anterior = NULL;
        lst->inicio = novo;
        lst->fim = novo;
    }
    else
    {
        lst->fim->proximo = novo;
        novo->anterior = lst->fim;
        novo->proximo= NULL;
        lst->fim = novo;
    }
    lst->tamanho++;
}

void imprimeIF(Lista *lst)
{
    if(!eVazia(lst))
    {
        Noh* pAux = lst->inicio;

        while (pAux != NULL)
        {
            cout << pAux->numero << " ";
            pAux = pAux->proximo;
        }
        cout << endl << "Tamanho da lista " << lst->tamanho << endl;
        cout << endl << endl;
    }
    else
        cout << endl << "Lista vazia...";
}

void imprimeFI(Lista *lst)
{
    if(!eVazia(lst))
    {
        Noh* pAux = lst->fim;

        while (pAux != NULL)
        {
            cout << pAux->numero << " ";
            pAux = pAux->anterior;
        }
        cout << endl << "Tamanho da lista " << lst->tamanho << endl;
        cout << endl << endl;
    }
    else
        cout << endl << "Lista vazia...";
}

void remover(Lista *lst, int valor){
    if (!eVazia(lst)) //remoção no início
    {
        Noh *pAux = lst->inicio;
        Noh *pApagar = NULL; //ponteiro para o nó ser removido

        if(pAux != NULL && lst->inicio->numero == valor)
        {
            pApagar = lst->inicio;
            lst->inicio = pApagar->proximo;
            if(lst->inicio == NULL)
                lst->fim = NULL;
            else
                lst->inicio->anterior = NULL;
        }
        else //remoção no meio ou fim
        {
            while (pAux != NULL && pAux->proximo != NULL && pAux->proximo->numero != valor)
                pAux = pAux->proximo;
            
            if(pAux != NULL && pAux->proximo != NULL)
            {
                pApagar = pAux->proximo;
                pAux->proximo = pApagar->proximo;
                if(pAux->proximo == NULL) //se o último elemento for removido
                    lst->fim = pAux;
                else
                    pAux->proximo->anterior = pAux;
            }
        }
        if(pApagar)
        {
            delete(pApagar); //Libera a memória do nó
            lst->tamanho--;  //Decrementa o tamanho da lista
        }
    }
    else
        cout << endl << "Lista vazia..." << endl << endl;
}

void esvaziar(Lista *lst)
{
    if(!eVazia(lst))
    {
        Noh *pAux;

        while (lst->inicio != NULL)
        {
            pAux = lst->inicio;
            lst->inicio = lst->inicio->proximo;
            delete(pAux);
        }
    }  
    else 
        cout << endl << "Lista vazia..." << endl << endl;
    
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
                cout << "Digite o numero a ser inserido no incio: ";
                cin >> numero;
                inserirInicio(&lista, numero);
            break;

            case 2:
                cout << "Digite o numero a ser inserido no fim: ";
                cin >> numero;
                inserirFim(&lista, numero);
            break;

            case 3:
                cout << "Imprimindo lista do inicio ao fim...";
                imprimeIF(&lista);
            break;

            case 4:
                cout << "Imprimindo lista do fim ao inicio...";
                imprimeFI(&lista);
            break;

            case 5:
                cout << "Digite o numero a ser removido: ";
                cin >> numero;
                remover(&lista, numero);
            break;

            case 6:
                cout << "Esvaziando lista...";
                esvaziar(&lista);
            break;

            case 7:
                cout << "Saindo...";
            break;
        }

     }while (opcao != 6);

    return 0;
}



