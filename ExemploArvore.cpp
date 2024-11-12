#include <iostream>

using namespace std;

typedef struct Arvore{
    int numero;
    Arvore *esquerda, *direita;
} Arvore;

int menu()
{
    int opcao;

    do{
        cout << endl << "MENU DE OPCOES" << endl;
        cout << "1 - Inserir numero na arvore" << endl;
        cout << "2 - Consultar um noh da arvore" << endl;
        cout << "3 - Consultar toda a arvore em ordem" << endl;
        cout << "4 - Consultar toda a arvore em pre-ordem" << endl;
        cout << "5 - Consultar toda a arvore em pos-ordem" << endl;
        cout << "6 - Excluir um noh da arvore" << endl;
        cout << "7 - Esvaziar a arvore" << endl;
        cout << "8 - Sair" << endl;

        cout << "Digite sua escolha: ";
        cin >> opcao;

        if(opcao < 1 || opcao > 8)
            cout << "\tEscolha invalida!" <<endl;
    }while(opcao < 1 || opcao > 8);

    return opcao;
}

bool eVazia(Arvore *arvore)
{
    if(arvore == NULL)
        return true;
    return false;
}

Arvore *inserir(Arvore *arvore, int numero)
{
    if (arvore == NULL)
    {
        arvore = new Arvore();
        arvore ->numero = numero;
        arvore ->esquerda = NULL;
        arvore->direita = NULL;
    }

    else if(numero < arvore->numero)
        arvore->esquerda = inserir(arvore->esquerda, numero);

    else
        arvore->direita = inserir(arvore->direita, numero);

    return arvore;
}

void mostrarEmOrdem(Arvore *arvore)
{
    if(arvore != NULL)
    {
        mostrarEmOrdem(arvore->esquerda);
        cout << arvore->numero << " ";
        mostrarEmOrdem(arvore->direita);
    }
}

void mostrarPreOrdem(Arvore *arvore)
{
    if(arvore != NULL)
    {
        cout << arvore->numero << " ";
        mostrarEmOrdem(arvore->esquerda);
        mostrarEmOrdem(arvore->direita);
    }
}

void mostrarPosOrdem(Arvore *arvore)
{
    if(arvore != NULL)
    {
        mostrarEmOrdem(arvore->esquerda);
        mostrarEmOrdem(arvore->direita);
        cout << arvore->numero << " ";
    }
}

int consultar(Arvore *arvore, int numero, int achou)
{
    if(arvore != NULL && achou == 0)
    {
        if(arvore->numero == numero)
            achou = 1;
        
        else if(numero < arvore->numero)
            achou = consultar(arvore->esquerda, numero, achou);
        else 
            achou = consultar(arvore->direita, numero, achou);
    }

    return achou;
}

Arvore *remover(Arvore *arvore, int numero)
{
    Arvore *pAux1, *pAux2;

    if(arvore->numero == numero)
    {
        if(arvore->esquerda == arvore->direita)
        {
            //O elemento a ser removido não tem filhos
            delete arvore;
            return NULL;
        }
        else if(arvore->esquerda == NULL)
        {
            //O elemento a ser removido não tem filhos a esquerda
            pAux1 = arvore->direita;
            delete arvore;
            return pAux1;

        }
        else if(arvore->direita == NULL)
        {
            //O elemento a ser removido não tem filhos a direita
            pAux1 = arvore->esquerda;
            delete arvore;
            return pAux1;

        }
        else
        {
            //O elemento a ser removido tem filhos dos 2 lados
            pAux2 = arvore->direita;
            pAux1 = arvore->direita;

            while (pAux1->esquerda != NULL);
                pAux1 = pAux1->esquerda;
            
            pAux1->esquerda = arvore->esquerda;
            delete arvore;
            return pAux2;
            
        }
    }
}

int main()
{
    Arvore *raiz = NULL; *aux;

    int opcao, numero, achou;
    
    do{
        opcao = menu();
        switch(opcao)
        {
            case 1:
                cout << "Digite o numero a ser inserido na arvore:" << endl;
                cin >> numero;
                
                raiz = inserir(raiz, numero);
                cout << "Numero inserido na arvore" << endl;
            break;

            case 2:
                if(eVazia(raiz))
                    cout << "|/| Arvore vazia!" << endl;
                else
                {
                    cout << "Digite o numero; ";
                    cin >> numero;

                    achou = 0;
                    achou = consultar(raiz, numero, achou);

                    if(achou == 0)
                        cout << "|*| Numero nao encontrado na arvore" << endl;

                    else
                        cout << "|*| Numero encontrado na arvore" << endl;
                }
                
            break;

            case 3:
                if(eVazia(raiz))
                    cout << "|/| Arvore vazia!" << endl;
                else
                {
                    cout << "Listando os elementos em ordem..." << endl;
                    mostrarEmOrdem(raiz);
                    cout << endl;
                }
            break;

            case 4:
                if(eVazia(raiz))
                    cout << "|/| Arvore vazia!" << endl;
                else
                {
                    cout << "Listando os elementos em ordem..." << endl;
                    mostrarPreOrdem(raiz);
                    cout << endl;
                }
            break;

            case 5:
                if(eVazia(raiz))
                    cout << "|/| Arvore vazia!" << endl;
                else
                {
                    cout << "Listando os elementos em ordem..." << endl;
                    mostrarPosOrdem(raiz);
                    cout << endl;
                }
            break

            case 6:
                if(eVazia(raiz))
                    cout << "|/| Arvore vazia!" << endl;
                else
                {
                    cout << "Digite o numero; ";
                    cin >> numero;

                    achou = 0;
                    achou = consultar(raiz, numero, achou);

                    if(achou == 0)
                        cout << "|*| Numero nao encontrado na arvore" << endl;

                    else
                    {
                        raiz = remover(raiz, numero);
                        cout << "|*| Numero encontrado na arvore" << endl;
                    }
                }
            break

            default:
                cout << "Saindo..." << endl;
        }
    }while(opcao != 8);
    
    return 0;
}