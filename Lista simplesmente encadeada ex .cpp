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
        cout << endl << "MENU DE OPCOES" << endl;
        cout << "1- Inserir no inicio da lista" << endl;
        cout << "2- Inserir no fim da lista" << endl;
        cout << "3- Imprimir toda a lista" << endl;
        cout << "4- Remover da lista" << endl;
        cout << "5- Esvaziar a lista" << endl;
        cout << "6- Sair" << endl;

        cout << "Digite sua escolha: ";
        cin >> opcao;

        if(opcao < 1 || opcao > 6)
            cout << "\tEscolha invalida!" << endl;
    }while(opcao < 1 || opcao > 6);

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

void inserirFim(Lista *lst, int numero)
{
    Noh *novo = new Noh();
    novo ->numero = numero;
    novo ->proximo = NULL;

    if(eVazia(lst))
    {
        lst->inicio = novo;
        lst->fim = novo;
    }
    else
    {
        lst->fim->proximo = novo;
        lst->fim = novo;
    }
    lst->tamanho++;
}

void imprime(Lista *lst)
{
    if(!eVazia(lst))
    {
        Noh* pAux = lst->inicio;

        while (pAux != NULL)
        {
            cout << pAux->numero << " ";
            pAux = pAux->proximo;
        }
        cout << endl << "Tamanho de lista" << lst->tamanho << endl;
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

