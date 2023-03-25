#include <iostream>
#include "BinaryTree.hpp"

using namespace std;

Tree::Tree()
{


	this->root = NULL;

}

Tree::Tree(const Tree& CopyTree)
{


	this->root = Tree::clone(CopyTree.root);	


}

Tree& Tree::operator = (const Tree& CopyTree)
{
 
	this->root = Tree::clone(CopyTree.root);

};

void Tree::print()
{
	cout << endl;

	print_node(this->root);

}

bool Tree::insert( const int key )
{
	
	this->root = add( this->root, key );

}

bool Tree::contains(const int key) const
{

	return Tree::check(this->root, key);

}

bool Tree::erase(const int key) 
{

	Tree::delete_node(this->root, key);

};

void Tree::delete_node(Node* node, const int key)
{
	if (!node);


	if (key < node->data)
	{
		delete_node(node->left, key);
	}

	else if (key > node->data)
	{
		delete_node(node->right, key);
	}
	else
	{
		if (!node->left)
		{
			Node* tmp = node->right;
			delete node;
			node = tmp;
		}
		else if (!node->right)
		{
			Node* tmp = node->left;
			delete node;
			node = tmp;
		}
		else
		{
			Node* tmp = find_min(node->right);
			node->data = tmp->data;
			delete_node(node->right, tmp->data);
		}
		
	}
};

bool Tree::clear()
{
	
	Tree::clear_node(this->root);

}

Tree::~Tree()
{

	this->clear();
	delete this->root;

}

size_t lcg() {
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}