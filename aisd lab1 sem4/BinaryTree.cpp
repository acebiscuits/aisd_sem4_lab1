#include <iostream>
#include <stdlib.h>
#include "BinaryTree.hpp"

using namespace std;

//Tree::Tree()
//{
//
//
//	this->root = NULL;
//
//}

Tree::Tree(const Tree& CopyTree)
{


	this->root = Tree::clone(CopyTree.root);	


}

Tree& Tree::operator = (const Tree& CopyTree)
{
 
	this->root = Tree::clone(CopyTree.root);
	return *this;
};

void Tree::print()
{
	//cout << endl;

	print_node(this->root);

}

bool Tree::_insert( const int key )
{
	this->root = add( this->root, key );
	return 1;
}

bool Tree::contains(const int key) const
{

	return Tree::check(this->root, key);

}

bool Tree::erase(const int key)
{

	this->root = delete_node(this->root, key);
	return 1;
};




void Tree::clear()
{
	
	Tree::clear_node(this->root);

}

Tree::~Tree()
{

	this->clear();
	delete this->root;

}

