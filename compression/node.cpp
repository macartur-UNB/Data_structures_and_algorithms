#include "node.h"
#include <iostream>
	
Node::Node(char value,int weight,Node* left , Node* right)
	: value(value),weight(weight), left(left),right(right)
{
}

Node::~Node()
{
}

void
Node::to_string()
{
	cout << "Node ("<< this->value <<":"<< this->weight <<")"<<endl;
}
	
bool 
Node::operator<(const Node& j ) const
{
	return this->weight > j.weight;
}

void 
Node::crossing()
{
	if ( this->left)
		this->left->crossing();
	this->to_string();
	if (this->right)
		this->right->crossing();
}

string 
Node::code(const char &a)const 
{
	string reverse_code;
	search_code(a,reverse_code);
	return string(reverse_code.rbegin(),reverse_code.rend());
}

bool
Node::search_code(const char &a,string &code)const
{
	if (this->value == a)
	{
		return true;
	}
	if (this->left and this->left->search_code(a,code))
	{
		code+='0';
		return true;
	}
	if (this->right and this->right->search_code(a,code))
	{
		code += '1';
		return true;
	}
	return false;
}
