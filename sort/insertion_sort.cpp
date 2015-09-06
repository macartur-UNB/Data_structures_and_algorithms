#include <iostream>
#include <vector>

using namespace std;


void insertion_sort(vector<int> &array)
{
    int tmp;
    int size = array.size();
    int eleito,j,i;

    for(i=1;i<size;i++)
    {
        eleito = array[i];
        for( j=i-1;j>=0 && array[j] > eleito;j--)
        {
            array[j+1] = array[j];
        }
        array[j+1] = eleito;
    }

}

int main()
{
    int a[] = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    vector<int> array(a,a+sizeof(a)/sizeof(int)); 
    insertion_sort(array);
    for(int i=0;i<array.size();i++)
    { 
        if (i>0)
            cout << " ";
        cout << array[i];
    }
    return 0;
}
