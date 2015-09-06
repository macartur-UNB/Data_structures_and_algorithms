#include <iostream>
#include <vector>

using namespace std;


void selection_sort(vector<int> &array)
{
    int tmp;
    int min;
    int size = array.size();
    for(int i=0;i<size;i++)
    {
        min = i;
        for(int j=i+1;j<size;j++)
        {
            if ( array[j] < array[min]  )   
                min = j;
        }
        if ( min != i )
        {
            tmp  = array[i];
            array[i] = array[min];
            array[min] = tmp;
        }
    }
}


int main()
{
    int a[] = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    vector<int> array(a,a+sizeof(a)/sizeof(int)); 
    selection_sort(array);
    for(int i=0;i<array.size();i++){
        if ( i > 0)
            cout << " ";
        cout << array[i] ;
    }
    return 0;
}
