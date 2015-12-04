#include <iostream>

#define MAX  10000
using namespace std;

int knapsack_recursion(int W,int weights[],int values[],int n)
{
    if ( n == 0 || W == 0)
      return 0;
    if (  weights[n-1] > W  )
      return knapsack_recursion(W,weights,values,n-1);
    else
      return max(values[n-1]+knapsack_recursion(W-weights[n-1],weights,values,n-1),
                 knapsack_recursion(W,weights,values,n-1));
}
int knapsack_interation(int W,int weights[],int values[],int n)
{
  int i,w;
  int k[n+1][W+1];

  for(i=0;i<=n;i++)
  {
    for(w=0;w<=W;w++)
    {
      if (i == 0 || w == 0 )
        k[i][w] = 0;
      else if (weights[i-1] > w)
        k[i][w] = k[i-1][w];
      else
        k[i][w] = max(values[i-1]+k[i-1][w-weights[i-1]],k[i-1][w]);
    }
  }
  return k[n][W];
}


int main()
{
  int n;
  int W;
  int weights[MAX];
  int values[MAX];
  cin >> W;
  cin >> n;
  for(int i=0;i<n;i++)  cin >> values[i] >> weights[i] ;
  cout << knapsack_recursion(W,weights,values,n) << endl;
  cout << knapsack_interation(W,weights,values,n) << endl;
}
