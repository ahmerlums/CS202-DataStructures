#ifndef __AVL_H
#define __AVL_H
#include <cstdlib>
#include <vector>
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;


template <class T>
struct AvLNode
{
	string value;
	int height;
	T key;
	AvLNode *parent; // pointer to parent node
	AvLNode *left; // pointer to left child
	AvLNode *right; // pointer to right child

	/*You can add additional variables if necessary*/

	AvLNode(string Val, T k)
	{
		this->value = Val;
		this->key = k;
		this->parent = NULL;
		this->left = NULL;
		this->right = NULL;
		this->height = 0;
	}
};
template <class T>
class AvL
{
	AvLNode<T> *root;

public:
	// Constructor
	AvL();

	// Destructor
	~AvL();

	// Insertion Function
	void insert(string val, T k); // inserts the given key value pair into the tree

	void delete_node(T k); // deletes the node for the given key
    AvLNode<T>* delete_node(AvLNode<T>*,T k);

	AvLNode<T> *search(T k); // takes key as an input and returns the node pointer if key exists and NULL pointer if key does not exists
	AvLNode<T>* search(AvLNode<T>*,T);
	AvLNode<T>* bst_insert(AvLNode<T>* t,string val,T key);
	void replace(T oldk, T newk); // replaces old key with the new key, value remains same.
    AvLNode<T>* Find_imBalance(AvLNode<T>* node);
    void Balance(AvLNode<T>* node);
    void recompheight(AvLNode<T>*);
	int nodeHeight(AvLNode<T> *n); // returns height of the subtree from given node

	AvLNode<T> *getRoot(); // returns root of the AVL tree

	/*You can add additional functions if necessary*/
};

#endif
