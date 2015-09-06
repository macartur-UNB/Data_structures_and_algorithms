#include <iostream>
#include <vector>

using namespace std;


vector<int> counting_sort(vector<int> &array)
{
    int size = array.size();
    int max;

    vector<int> sorted_vector(size,0);

    // verifica o maior elemento
    max = -1;
    for(int i=0;i<size;i++)
    {
        if ( array[i] > max)
            max = array[i];
    }

    // criar um array com zeros
    vector<int> elements(max+1,0);

    // percorre o vetor colocando
    // os elementos no array
    for(int i=0;i<size;i++)
        elements[array[i]]++;

    // percorre o array ajustando com
    // a quantidade de elementos anteriores
    for(int i=1;i<max+1;i++)
        elements[i] += elements[i-1];

    // percorre do fim do vetor para o inicio
    // colocando os elementos em ordem
    for(int i=size-1;i>=0;i--)
    {
        sorted_vector[elements[array[i]]-1] = array[i];
        elements[array[i]]-=1;
    }
    return sorted_vector;
}

int main()
{
    int a[] = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    vector<int> array(a,a+sizeof(a)/sizeof(int));
    vector<int> result = counting_sort(array);
    for(int i=0;i<result.size();i++)
    {
        if (i)
            cout << " ";
        cout << result[i];
    }
    return 0;
}
