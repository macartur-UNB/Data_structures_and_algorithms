#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> left, vector<int> right);
vector<int> merge_sort(vector<int> & array)
{
    if ( array.size() <= 1)
        return array;

    int middle = array.size()/2;        // pega o elemento do meio
    
    vector<int> left(array.begin(),array.begin()+middle);// cria os elementos da esquerda
    vector<int> right(array.begin()+middle,array.end());// cria os elementos da direita

    vector<int> result_left = merge_sort(left); 
    vector<int> result_right = merge_sort(right); 

    return merge(result_left,result_right);
}

vector<int> merge( vector<int> left, vector<int> right)
{
    vector<int> merged_array;

    int i,j;
    i=j=0;
    while( i < left.size() && j< left.size() )
    {
        if ( left[i] <= right[j] )
        {
            merged_array.push_back(left[i]);
            i++;
        }else
        {
            merged_array.push_back(right[j]);
            j++;
        }
    }

    while(i < left.size())
    {
        merged_array.push_back(left[i]);
        i++;
    }
    while(j < right.size())
    {
        merged_array.push_back(right[j]);
        j++;
    }

    return merged_array;
}


int main()
{
    int a[] = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    vector<int> array(a,a+sizeof(a)/sizeof(int)); 
    vector<int> merged = merge_sort(array);
    for(int i=0;i<merged.size();i++)
    { 
        if (i>0)
            cout << " ";
        cout << merged[i];
    }
    return 0;
}
