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

  g.add(1,2,2);
  g.add(2,3,1);
  g.add(1,3,8);
  g.add(1,5,5);
  g.add(5,4,4);
  g.add(3,4,3);

  cout << "Busca em largura: "<<endl;
  g.search_BFS(1,4);
  cout << "\n"<<endl;

  cout << "busca em profundidade: "<<endl;
  g.search_DFS(1,4);

  cout << "dijkstra: "<<endl;
  cout << g.dijkstra(1,4)<<endl;

  cout << endl;
  cout << "to_string"<<endl;
  g.to_string();
  return 0;
}
