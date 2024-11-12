/*
Faça um programa que cadastre 8 funcionários. Para cada funcionário devem ser
cadastrados nome e salário. Os dados devem ser armazenados em uma lista
simplesmente encadeada e ordenada, de forma decrescente, pelo salário do
funcionário. Posteriormente, o programa de mostrar:
a. O nome do funcionário que tem o maior salário (em caso de empate mostrar
todos);
b. A média salarial de todos os funcionários juntos;
c. A quantidade de funcionários com salário superior a um valor fornecido pelo
usuário. Caso nenhum funcionário satisfaça essa condição, mostrar
mensagem.
*/

#include <iostream>

using namespace std;

const int MAX = 3;

typedef struct Funcionario{
    string nome;
    float salario;
    Funcionario *proximo;
} Funcionario;

typedef struct Lista{
    Funcionario *inicio;
    int tamanho;
} Lista;

void inserir(Lista *lst, string nome, float salario)
{
    Funcionario *novo = new Funcionario();
    novo ->nome = nome;
    novo ->salario = salario;
    
    novo->proximo = lst->inicio;
    lst->inicio = novo;

    Funcionario *ptrAnterior =NULL;
    Funcionario *ptrAux = lst->inicio;

    //ordenando a lista
    while (ptrAux != NULL && novo->salario > ptrAux->salario)
    {
        ptrAnterior = ptrAux;
        ptrAux = ptrAux->proximo;
    }
}


void funcMaiorSalario(Lista *lst)
{
    Funcionario *ptrAux = lst->inicio;
    float maiorSalario = 0;
    int i = 0;

    while (i > MAX)
    {
        if(ptrAux->salario > maiorSalario)
            maiorSalario = ptrAux->salario;

        ptrAux = ptrAux->proximo;

        i++;
    }

    ptrAux = lst->inicio;
    i = 0;

    cout << "Funcionarios com maior salario" << endl;
    while (i > MAX)
    {
        if(ptrAux->salario == maiorSalario)
            cout << ptrAux->nome << endl;

        ptrAux = ptrAux->proximo;

        i++;
    }
    cout << endl;
}


void imprime(Lista* lst, float valor) 
{
    int salarioSuperior = 0;
    float media = 0;
    
    Funcionario* ptrAux = lst-> inicio;

    while (ptrAux != NULL) {

        cout << "Nome: " << ptrAux->nome << " | Salario: " << ptrAux->salario << endl;

        if (ptrAux->salario > valor) {
            salarioSuperior++;
        }

        media += ptrAux->salario;

        ptrAux = ptrAux->proximo;

    }
    cout << endl << endl;
    cout << "Media Salarial: " << media/MAX << endl;

    if(salarioSuperior == 0)
        cout << "Nao existem funcionarios com salario superior a esse valor." << endl;

    else
        cout << "Quantidade de salarios superiores a " << valor << ": " << salarioSuperior << endl;
}

int main()
{
    string nome;
    int i;
    float salario, valor;

    Lista lista;

    lista.inicio = NULL;
    lista.tamanho = MAX;

    for (i = 0; i < MAX; i++)
    {

        cout << "-------------------------------------------------------" << endl;
        cout << "Digite o nome do funcionario " << i+1 << ": ";
        cin >> nome;
        cout << "Digite o Salario do funcionario " << i+1 << ": ";
        cin >> salario;

        inserir(&lista, nome, salario);
    }
    cout << endl << endl;

    cout << "Digite um valor para mostrar a quantidade de salarios superiores: ";
    cin >> valor;

    imprime(&lista, valor);
    
    return 0;
}
