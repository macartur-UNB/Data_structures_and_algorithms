#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
  Graph g;
  g.add_node(1);
  g.add_node(2);
  g.add_node(3);
  g.add_node(4);
  g.add_node(5);
  g.add_node(6);
  g.add(6,4,1);
  g.add(4,5,1);
  g.add(4,3,1);
  g.add(3,2,1);
  g.add(5,2,1);
  g.add(5,1,1);
  cout << "Busca em largura: "<<endl;
  g.search_BFS(6);
  cout << "\n"<<endl;
  cout << "busca em profundidade: "<<endl;
  g.search_DFS(6);

  cout << endl;
  cout << "to_string"<<endl;
  g.to_string();
  return 0;
}
