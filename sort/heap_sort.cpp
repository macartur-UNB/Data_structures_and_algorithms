#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// MAX HEAP
class Heap
{
    private:
        int* array;
        int size;
        int capacity;
        void heapify_with_father(int index);
        void heapify(int index);
    public:
        Heap(int size=4);
        void push(int num);
        void heapsort();
        void display();
        int top();
        int back();
        void pop();
        bool empty();
};

Heap::Heap(int size)
{
    this->array = (int*) malloc(size*sizeof(int));
    this->capacity = size;
    this->size = 1;
    for(int i=0;i<capacity;i++)
        this->array[i] = 0;
}

void
Heap::push(int num)
{
    if (  size >=  capacity )
        this->array = (int*) realloc(this->array,this->capacity*2*sizeof(int));
    this->array[size] = num;
    this->size++;
    heapify_with_father(size-1);
}

void
Heap::heapify_with_father(int index)
{
    if (index == 0)
        return;
    // verifica se o pai é maior que o filho
    if ( this->array[index/2] < this->array[index] && index/2 != 0)
    {
        int tmp = this->array[index];
        this->array[index] = this->array[index/2];
        this->array[index/2] = tmp;
        heapify_with_father(index/2);
    }
}

void
Heap::heapify(int index)
{
    if ( this->array[index*2] >  this->array[index*2+1] )
    {
        if ( this->array[index*2] > this->array[index] )
        {
            int tmp = this->array[index];
            this->array[index] = this->array[index*2];
            this->array[index*2] = tmp;
            if ( index*2 >= this->size-1 ) return;
            heapify(index*2);
        }
    }else{
        if ( this->array[index*2+1] > this->array[index] )
        {
            int tmp = this->array[index];
            this->array[index] = this->array[index*2+1];
            this->array[index*2+1] = tmp;
            if ( index*2+1 >= this->size-1 ) return;
            heapify(index*2+1);
        }
    }
}

int
Heap::top()
{
    return this->array[1];
}

void
Heap::pop()
{
    this->array[1] = this->array[this->size-1];
    this->array[this->size-1] = 0;
    this->size--;
    heapify(1);
}

void
Heap::display()
{
    for(int i=1;i<this->size;i++)
    {
        cout << "|" << this->array[i] << "|";
    }
    cout << endl;
}

bool
Heap::empty()
{
    return this->size-1 <= 0;
}

int main()
{
    int a[] = {2,7,26,25,19,17,1,90,3,36};
    Heap myheap = Heap();
    for(int i=0;i<10;i++)
    {
       cout << "Colocando o elemento:" << a[i] << endl;
       myheap.push(a[i]);
       myheap.display();
    }
    cout << endl;
    cout << "Pop elements"<<endl;
    while(not myheap.empty())
    {
        cout << "Element: " << myheap.top()<<endl;
        myheap.pop();
        myheap.display();
    }

    return 0;
}
