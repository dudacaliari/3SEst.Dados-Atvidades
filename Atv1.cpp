/*Faça um programa que cadastre 5 produtos. Para cada produto devem ser
cadastrados código do produto, preço e quantidade estocada. Os dados devem ser
armazenados em uma lista simplesmente encadeada e não ordenada. Posteriormente,
receber do usuário a taxa de desconto (ex.: digitar 10 para taxa de desconto de 10%).
Aplicar a taxa digitada ao preço de todos os produtos cadastrados e finalmente
mostrar um relatório com o código e o novo preço. O final desse relatório deve
apresentar também a quantidade de produtos com quantidade estocada superior a
500.*/

#include <iostream>

using namespace std;

const int MAX = 5;

typedef struct Produto{
    int codigo;
    float preco;
    int quantidade;
    Produto *proximo;
} Produto;

typedef struct Lista{
    Produto *inicio;
    int tamanho;
} Lista;

void inserir(Lista *lst, int codigo, float preco, int quantidade)
{
    Produto *novo = new Produto();
    novo ->codigo = codigo;
    novo ->preco = preco;
    novo ->quantidade = quantidade;
    
    novo->proximo = lst->inicio;
    lst->inicio = novo;
}

void aplicarDesconto(Lista *lst, float taxaDesconto) 
{
    Produto *produtoAtual = lst->inicio;
    while (produtoAtual != nullptr) {
        produtoAtual->preco *= (1 - taxaDesconto/100);
        produtoAtual = produtoAtual->proximo;
    }
}

void imprime(Lista* lst) 
{
    int Estoque500 = 0;

    Produto* produtoAtual = lst-> inicio;

    while (produtoAtual != nullptr) {
        cout << "Codigo: " << produtoAtual->codigo << " - Novo Preco: R$" << produtoAtual->preco << endl;
        if (produtoAtual->quantidade > 500) {
            Estoque500++;
        }
        produtoAtual = produtoAtual->proximo;
    }
    cout << "Quantidade de produtos com quantidade estocada superior a 500: " << Estoque500 << endl;
}

int main()
{
    int codigo, quantidade, i;
    float preco, taxaDesconto;

    Lista lista;

    lista.inicio = NULL;
    lista.tamanho = MAX;

    for (i = 0; i < MAX; i++)
    {

        cout << "-------------------------------------------------------" << endl;
        cout << "Digite o codigo do produto " << i+1 << ": ";
        cin >> codigo;
        cout << "Digite o preco do produto " << i+1 << ": ";
        cin >> preco;
        cout << "Digite a quantidade estocada do produto " << i+1 << ": ";
        cin >> quantidade;

        inserir(&lista, codigo, preco, quantidade);
    }
    cout << endl << endl;

    cout << "Digite a taxa de desconto a ser aplicada (em %): ";
    cin >> taxaDesconto;
    aplicarDesconto (&lista, taxaDesconto);

    imprime(&lista);
    
    return 0;
}
