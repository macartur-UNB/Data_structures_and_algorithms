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
    int a[] = {20,2,10,15,4};
    vector<int> array(a,a+sizeof(a)/sizeof(int)); 
    bubble_sort(array);
    for(int i=0;i<array.size();i++){ cout << array[i] << " ";    }
    return 0;
}
