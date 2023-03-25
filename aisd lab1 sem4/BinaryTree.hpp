#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


class Tree
{
private:
	struct Node
	{

		int data;
		Node* left;
		Node* right;

		Node( int data = 0 ) : data( data ), left( NULL ), right( NULL ) {};

	};

	Node* root;

public:

	Tree();//+

	Tree(  const Tree& CopyTree  );//+

	Tree& operator = (const Tree& CopyTree);//+

	Node* clone(  const Node* node  )
	{

		if (node == NULL)
		{

			return NULL;
		}

		Node* node_new = new Node (  node->data  );
		node_new->left = clone(  node->left  );
		node_new->right = clone (  node->right  );
		
		return node_new;

	}

	void print();//-

	void print_tree(const Node* node);//-

	bool insert(int key);//-

	Node* add(Node* root, const int key)
	{

	};//-

	bool contains(int key) const;

	bool erase(int key);

	bool clear();

	~Tree();

};