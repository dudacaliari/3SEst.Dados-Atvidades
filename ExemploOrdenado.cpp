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
        cout << "1 - Inserir numero na lista" << endl;
        cout << "2 - Imprimir toda a lista" << endl;
        cout << "3 - Remover da lista" << endl;
        cout << "4 - Esvaziar a lista" << endl;
        cout << "5 - Sair" << endl << endl;

        cout << "Digite sua escolha: ";
        cin >> opcao;

        if(opcao < 1 || opcao > 6)
            cout << "\tEscolha invalida!" <<endl;
    }while(opcao < 1 || opcao > 6);

    return opcao;
}

bool eVazia(Lista *lst)
{
    /*funcao auxiliar para perguntar se eh vazia
    evitando que refaca o if abaixo nas outras funcoes*/
    
    if(lst->inicio == NULL)
        return true;
    return false;
}

void inserir(Lista *lst, int numero)
{
    Noh *novo = new Noh(); //criando caixinha
    novo->numero = numero;

    if(eVazia(lst))
    {
        /*primeiro elemento dentro da lista caso ela seja vazia
        inicio e fim apontarao para o mesmo numero e proximo apontara para NULL*/
        novo->proximo = NULL;
        lst->inicio = novo;
        lst->fim = novo;
    }

    else
    {
        Noh *ptrAnterior =NULL;
        Noh *ptrAux = lst->inicio;
        
        while (ptrAux != NULL && novo->numero < ptrAux->numero)
        {
            ptrAnterior = ptrAux;
            ptrAux = ptrAux->proximo;
        }

        if(ptrAnterior == NULL)
        {
            novo->proximo = lst->inicio;
            lst->inicio = novo;
        }

        else if (ptrAux == NULL)
        {
            lst->fim->proximo = novo;
            lst->fim = novo;
        }
        
        else
        {
            ptrAnterior->proximo = novo;
            novo->proximo = ptrAux;
        }   
    }

    lst->tamanho++;
}
    
void imprime(Lista *lst)
{
    if(!eVazia(lst))
    {
        Noh *ptrAux = lst->inicio;

        while(ptrAux != NULL)
        {
            cout << ptrAux->numero << " ";
            ptrAux = ptrAux->proximo;
        }

        cout << endl << "Tamanho da Lista: " << lst->tamanho << endl;
        cout << endl << endl;
    }

    else
        cout << endl << "Lista vazia..." << endl << endl;
}

void remover(Lista *lst, int valor)
{
    if(!eVazia(lst))
    {
        Noh *ptrAux = lst->inicio;
        Noh *ptrApagar = NULL;
        
        if(ptrAux != NULL && lst->inicio->numero == valor)
        {
            // remover o 1 elemento
            ptrApagar = lst->inicio;
            lst->inicio = ptrApagar->proximo;
            if(lst->inicio == NULL)
                lst->fim = NULL;
        }

        else
        {
            //remocao no meio ou final
            while(ptrAux != NULL && ptrAux->proximo != NULL && ptrAux->proximo->numero != valor)
                //1 condicao: permite navegar?
                //2: o proximo tem um campo preenchido?
                //3: o numero do proximo valor eh diferente do valor buscado?
                ptrAux = ptrAux->proximo;
                //se tudo for sim, o ptrAux anda buscando o numero na proxima casa
                // ao encontrar, ptrAux aponta pro numero anterior, e pApagar aponta para o numero buscado e apaga;

            if(ptrAux != NULL && ptrAux->proximo !=NULL)
            {
                //se proximo for nulo, significa que ptrApagar esta apontando pro ultimo
                ptrApagar = ptrAux->proximo;
                ptrAux->proximo = ptrApagar->proximo;
                if(ptrAux->proximo == NULL) //confere se o proximo elemento eh nulo
                    lst->fim = ptrAux;
            } 
        }
        if(ptrApagar)
        {
            delete(ptrApagar); //Libera a memoria do noh
            lst->tamanho--; //decrementa tamanho da lista
        }
    }

    else
        cout << endl <<  "Lista vazia..." << endl << endl;
}

void esvaziar(Lista *lst)
{
    if(!eVazia(lst))
    {
        Noh *ptrAux;

        while(lst->inicio != NULL)
        {
            ptrAux = lst->inicio;
            lst->inicio = lst->inicio->proximo; //percorrendo a lista com loop
            delete(ptrAux); //deletando um por um
        }
    }

    else
        cout << endl << "Lista vazia..." << endl << endl;
}

int main()
{
    Lista lista;

    //Inicializacao da lista:
    lista.inicio = NULL;
    lista.fim = NULL;
    lista.tamanho = 0;
    
    int opcao, numero;
    
    do{
        opcao = menu();
        switch(opcao)
        {
            case 1:
                cout << "Digite o numero a ser inserido na lista:" << endl;
                cin >> numero;
                inserir(&lista, numero);
                break;
            case 2:
                cout << "Imprimindo a lista..." << endl;
                imprime(&lista);
                break;
            case 3:
                cout << "Digite o numero a ser removido no fim da lista:" << endl;
                remover(&lista, numero);
                break;
            case 4:
                cout << "Esvaziando a lista..." << endl;
                esvaziar(&lista);
                break;
            default:
                cout << "Saindo..." << endl;
        }
    }while(opcao != 6);
    
    return 0;
}