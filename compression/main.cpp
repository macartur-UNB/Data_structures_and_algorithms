#include <iostream>
#include <map>
#include <queue>
#include "node.h"

using namespace std;

priority_queue<Node> create_nodes(string text)
{
    map<char,int> frequence;
    priority_queue<Node> result;

    unsigned int size = text.size();
    for(unsigned int i = 0;i<size;i++) 
    {
        if ( frequence.find(text[i]) == frequence.end() )
        {
            frequence[text[i]] = 1;
        }
        else
        {
            frequence[text[i]]++;
        }
    }

    for(auto it = frequence.begin();it != frequence.end();it++)
    {
        result.push(Node(it->first,it->second));
    }

    return result;
}

Node make_tree(priority_queue<Node> elements)
{
    while(elements.size() > 1)
    {
        Node* tmp_left = new Node(elements.top().value,elements.top().weight,elements.top().left,elements.top().right);
        elements.pop();

        Node* tmp_right = new Node(elements.top().value,elements.top().weight,elements.top().left,elements.top().right);
        elements.pop();

        Node new_node(0,tmp_left->weight + tmp_right->weight,tmp_left,tmp_right);
        elements.push(new_node);
    }
    return elements.top();
}

int main()
{
    string text;
    priority_queue<Node> elements;

    getline(cin,text);
    
    elements =create_nodes(text);
    Node tree = make_tree(elements);

    unsigned int size = text.size();

    for(unsigned int i=0;i<size;i++)
        cout << tree.code(text[i]);
    cout << endl;


    return 0;
}
