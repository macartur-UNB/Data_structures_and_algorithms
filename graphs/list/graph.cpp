#include "graph.h"
#include <algorithm>
#include <list>
#include <stack>
#include <iostream>
#include <utility>


Graph::Graph()
{
}
Graph::~Graph()
{
}


void
Graph::add_node(int data)
{
  nodes[data] = vector< pair< int,int> >();
}
void
Graph::remove_node(int data)
{
  nodes.erase(data);
}

void
Graph::add(int v1,int v2, int weight)
{
  nodes[v1].push_back(make_pair(v2,weight));
}

void
Graph::remove(int v1,int v2)
{
  int size = nodes[v1].size();
  for(int i=0;i<size;i++)
  {
      if ( nodes[v1][i].first == v2)
      {
        nodes[v1].erase(nodes[v1].begin(), nodes[v1].begin()+i+1);
      }
  }
}

void
Graph::to_string()
{
  for(auto node : nodes)
  {
    int size_neighbors = node.second.size();
    cout << node.first << ": ";
    for(int j=0;j<size_neighbors;j++)
    {
      cout << "("<<node.second[j].first << ", "<<node.second[j].second <<") ";
    }
    cout << endl;
  }
}

void
Graph::search_BFS(int root)
{
  list< int> visited,to_visit;

  to_visit.push_back(root);

  while(not to_visit.empty())
  {
      visited.push_back(root);

      cout << root << endl;

      to_visit.pop_front();
      int size = nodes[root].size();
      for(int i=0;i<size;i++)
      {
        if ((find(visited.begin(),visited.end(),nodes[root][i].first) == visited.end()) && (find(to_visit.begin(),to_visit.end(),nodes[root][i].first) == to_visit.end()) )
        {
          to_visit.push_back(nodes[root][i].first);
        }
      }
      root = to_visit.front();
  }
}

void
Graph::search_DFS(int root)
{
  list<int> visited;
  stack<int> pilha;

  pilha.push(root);
  do
  {
    visited.push_back(root);
    cout << root <<endl;

    int size = nodes[root].size();

    for(int i=0;i<size;i++)
    {
      if ((find(visited.begin(),visited.end(),nodes[root][i].first) == visited.end()))
        pilha.push(nodes[root][i].first);
    }
    root = pilha.top();
    pilha.pop();
  }
  while(not pilha.empty());
}
