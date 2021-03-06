#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

// retorna o digito dado um indice da direita para a esquerda
int
digit(int number , int index)
{
	number = number/pow(10,index-1);
	return (number)%10;
}

// verifica se algum elemento do vetor possui o digito
// caso nao possua retorna false
bool
has_digit(vector<int> & elements,int digito)
{
	int size = elements.size();
	for(int i=0;i<size;i++)
		if (digit(elements[i],digito))
			return true;
	return false;
}

// operação de count sort sobre um digito
vector<int>
count_sort(vector<int> elements, int current_digit)
{
	int size= elements.size();
	vector<int> all_digits(10,0);
	vector<int> result(size,0);
	int value;


	for(int i=0;i<size;i++)
	{
		value = digit(elements[i], current_digit);
		all_digits[value] +=1;
	}

	for(int i=1;i<10;i++) all_digits[i] += all_digits[i-1];


	for(int i=size-1;i >= 0;i--)
	{
		value = digit(elements[i],current_digit);
		result[ all_digits[value]-1 ] = elements[i];
	    all_digits[value]--;
	}
	return result;
}


// percorre os digitos realizando um count sort
vector<int> 
radix_sort(vector<int>  elements)
{
	int current_digit = 1;
	vector<int> aux = elements;
	do
	{
		aux = count_sort(aux,current_digit);
		current_digit++;
	}while(has_digit(aux,current_digit));
	return aux;
}

int main(int argc , char *argv[])
{
    clock_t t;
    int data;
    bool print;
	vector<int> elements;
    ifstream infile; 

    if (argc == 1 || argc > 3 ){
         cout << "try to use ./prog <file_name> [--print]"<<endl;
         return 0;
    }
   
    if (argv[2])
        print = true;
    string file = argv[1];

    infile.open(file.c_str()); 
    while(infile >> data)
    {
        elements.push_back(data);
    }
    infile.close();

    t = clock();
	vector<int> result = radix_sort(elements);
    t = clock() - t;
    cout << "Time = "<< t << endl;

    if (print)
    {
        int size= result.size();
        for(int i=0;i<size;i++)
        {
            if (i)
                cout << " ";
            cout << result[i];
        }
        cout << endl;
    }
	return 0;
}
