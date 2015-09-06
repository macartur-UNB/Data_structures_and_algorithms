#include <iostream>
#include <vector>

using namespace std;


void bubble_sort(vector<int> &array)
{
    int size = array.size();
    int tmp;
    bool swapped;

    do
    {
        swapped = false;
        for(int i=1;i<size;i++)
            if ( array[i-1] > array[i] )
            {
                tmp = array[i-1];
                array[i-1] = array[i];
                array[i] = tmp;
                swapped = true;
            }
    }
    while(swapped);
}


int main()
{
    int a[] = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    vector<int> array(a,a+sizeof(a)/sizeof(int)); 
    bubble_sort(array);
    for(int i=0;i<array.size();i++){ cout << array[i] << " ";    }
    return 0;
}
