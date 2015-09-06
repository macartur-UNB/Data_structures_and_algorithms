#include <iostream>
#include <vector>

using namespace std;

void swap(int &i , int& j)
{
    int tmp = i;
    i = j;
    j = tmp;
}

void shell_sort(vector<int> &array,bool reverse)
{   
    int size = array.size();
    bool swapped;
    int deep;
    swapped = false;
    while( swapped || deep > 1  ) 
    {
        swapped = false;
        deep = (deep+1)/2; 
        for(int i=0;i < (size-deep);i++)
        {
            if ((reverse && array[i+deep] < array[i]) 
                 || 
                (!reverse && array[i+deep] > array[i]))
            {
                swap(array[i+deep],array[i]);
                swapped = true;
            }
        }
    }
}



int main()
{
    int a[] = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    vector<int> array(a,a+sizeof(a)/sizeof(int)); 
    shell_sort(array,true);
    for(int i=0;i<array.size();i++)
    { 
        if (i)
            cout << " ";    
        cout << array[i];
    }
    return 0;
}
