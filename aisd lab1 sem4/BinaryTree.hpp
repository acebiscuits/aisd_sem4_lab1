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

	void print_node(const Node* node) const
	{

		if (node != NULL)
		{

			cout <<node->data<<" ";
			print_node(node->left);
			print_node(node->right);
		}

		

	};//+

	bool _insert(int key);//+

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


	bool erase(int key);//+

	Node* find_min(Node* node)
	{

		Node* cur = node;
		while (cur->left)
		{
			cur = cur->left;
		}

		return cur;
	}

Node* delete_node(Node* node, const int key)
{
	if (!node)
	{
		cout <<endl<< "Такого эл-та нет";
		return NULL;
	}

		else if (key < node->data)
		{
		node->left = delete_node(node->left, key);
		}

		else if (key > node->data)
		{
		node->right = delete_node(node->right, key);
		}
		else
		{
			if (!node->left && !node->right)
			{
				cout << endl << "элемент " << key << " удален";
				delete node;
				//node = NULL;
				return NULL;
			}
			else if (!node->left)
			{
				cout << endl<<"элемент " << key << " удален";
				Node* tmp = node;
				node = node->right;
				delete tmp;
				
			}
			else if (!node->right)
			{
				cout <<endl<< "элемент " << key << " удален";
				Node* tmp = node;
				node = node->left;
				delete node;
				
			}
			else
			{
				cout <<endl<< "элемент " << key << " удален";
				Node* tmp = find_min(node->right);
				node->data = tmp->data;
				node->right = delete_node(node->right, tmp->data);
			}

		}
	return node;
};

bool clear();//+

Node* clear_node(Node* root)
{
	
		if (root->left)root->left = clear_node(root->left);
		else if (root->right)root->right = clear_node(root->right);
		else
		{
			delete root;
			root = NULL;
			return root;
		}
	
};

~Tree();//+

};