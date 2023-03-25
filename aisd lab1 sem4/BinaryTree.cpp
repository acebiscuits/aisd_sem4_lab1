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



size_t lcg() {
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}