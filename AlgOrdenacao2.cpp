#include <iostream>

using namespace std;

const int SIZE = 10;

void dataImput(float *vData)
{
    float *ptrAux = vData;
    int i;

    for(i=0; i<SIZE; i++)
    {
        cout << "Insira o "<< i+1 <<"o numero:" << endl;
        cin >> ptrAux[i];
    }
}

int main()
{
    float number[SIZE];
    int i;
    
    dataImput(number);

    for(i=0; i<SIZE; i++)
    {
        cout << number[i];
    }

}