#ifndef NODE
#define NODE
#include <iosfwd>
#include <string>
using namespace std;

class Node
{
public:
	Node *left;
	Node *right;
	char value;
	int weight;
	Node(char value=0, int weight=0,Node* left=nullptr, Node* right=nullptr);
	~Node();

	bool operator<(const Node& j ) const;
	void to_string();
	void crossing();
	string code(const char &a)const ;
	bool search_code(const char &a,string &code)const;
};

#endif
