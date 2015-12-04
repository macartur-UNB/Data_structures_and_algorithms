#include "graph.h"
#include <algorithm>
#include <list>
#include <stack>
#include <iostream>
#include <utility>
#include <map>


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

int
Graph::search_BFS(int root,int value)
{
  list< int> visited,to_visit;

  to_visit.push_back(root);

  while(not to_visit.empty())
  {
      visited.push_back(root);

      cout << root << endl;
      if ( root == value)
        return root;

      to_visit.pop_front();
      int size = nodes[root].size();
      for(int i=0;i<size;i++)
      {
        if ((find(visited.begin(),visited.end(),nodes[root][i].first) == visited.end()) and
            (find(to_visit.begin(),to_visit.end(),nodes[root][i].first) == to_visit.end()))
        {
          to_visit.push_back(nodes[root][i].first);
        }
      }
      root = to_visit.front();
  }
  return -1;
}

int
Graph::search_DFS(int root, int value)
{
  list<int> visited;
  stack<int> pilha;

  pilha.push(root);
  do
  {
    visited.push_back(root);
    cout << root <<endl;
    if (root ==  value)
    {
      return value;
    }

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
  return -1;
}

int
Graph::dijkstra(int v1, int v2)
{
  list< int> visited,to_visit;
  map<int,int> lig,min_path;
  int root = v1;
  for ( auto key : nodes )
  {
    lig[key.first] = 0;
    min_path[key.first] = 0;
  }
  to_visit.push_back(root);
  // making dijkstra algorithm
  while(not to_visit.empty())
  {
      visited.push_back(root);
      to_visit.pop_front();

      int size = nodes[root].size();
      for(int i=0;i<size;i++)
      {
        int current_path =  nodes[root][i].second + min_path[root];
        
        // verify if the current_path is smaller than last path until this node
        if ( lig[nodes[root][i].first] == 0 or  current_path < min_path[nodes[root][i].first])
        {
          min_path[nodes[root][i].first] = current_path;
          lig[nodes[root][i].first] = root;
        }
        // verify if that node was visited
        if ((find(visited.begin(),visited.end(),nodes[root][i].first) == visited.end()) and
            (find(to_visit.begin(),to_visit.end(),nodes[root][i].first) == to_visit.end()))
        {
              to_visit.push_back(nodes[root][i].first);
        }
      }
      root = to_visit.front();
  }
  return min_path[v2];
}

