#ifndef GRAPH_H
#define GRAPH_H

/*
 *  Grafo com lista de adjacências
 *
 * */

#include <vector>
#include <map>
using namespace std;

class Graph
{
private:
  map<int, vector<pair<int,int> > > nodes;
public:
  Graph();
  ~Graph();
  void add_node(int data);
  void remove_node(int data);
  void add(int v1,int v2, int weight=0);
  void remove(int v1,int v2);
  void to_string();
  void search_DFS(int root);
  void search_BFS(int root);
};

#endif
