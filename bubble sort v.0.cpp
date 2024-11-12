#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int x[5], n, i, aux;
    system("cls");

    for(i=0; i<5; i++)
    {
        cout<<"Digite o "<<i+1<<"° numero: ";
        cin>>x[i];
    }

    for(n=1; n<=5; n++)
    {
        for(i=0; i<4; i++)
        {
            if (x[i] > x[i + 1])
            {
                aux = x[i];
                x[i] = x[i+1];
                x[i+1] = aux;
            }
        }
    }

    for(i=0; i<5; i++)
    {
        cout << i+1 << " numero: " << x[i] << endl;
    }
    
    getch();

    return 0;
}