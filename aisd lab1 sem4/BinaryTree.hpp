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

	Tree() = default;//+

	Node* get_root()
	{
		return this->root;
	}

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

	void print();//+

	void print_node(const Node* node)
	{

		if (node)
		{

			cout <<node->data<<" ";
			print_node(node->left);
			print_node(node->right);
		}

		

	};//+

	void insert(int key);//+

	Node* add(Node* node, const int key)
	{

		if (!node)
		{
			return new Node(key );
		}

		if ( key  < node->data)
		{

			node->left =  add( node->left, key );

		}
		else 
		{

			node->right =  add(node->right, key);
		}
		return node;
	}

	bool contains( const int key) const;//+ 

	bool check(Node* node, const int key) const
	{

		if (!node)return false;

		if (node->data == key) return true;

		if (node->data > key)
		{
			return check(node->left, key);
		}

		return check(node->right, key);

	}


	void erase(int key);//+

	Node* find_min(Node* node)
	{

		Node* cur = node;
		while (cur && cur->left)
		{
			cur = cur->left;
		}

		return cur;
	}

void delete_node(Node* node, const int key);

void clear();//+

void clear_node(Node* root)
{

	if (root->left)clear_node(root->left);
	if (root->right)clear_node(root->right);

	if (!root->left && !root->right)delete root;
	root = NULL;

};

~Tree();//+

};