// intbst.cpp
// Implements class IntBST
// YOUR NAME(S), DATE

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() : root(0) { }

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    if (n) {
	clear(n->left);
	clear(n->right);
	delete n;
    }
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    // handle special case of empty tree first
    if (!root) {
	root = new Node(value);
	return true;
    }
    // otherwise use recursive helper
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    if (value == n->info)
	return false;
    if (value < n->info) {
	if (n->left)
	    return insert(value, n->left);
	else {
	    n->left = new Node(value);
	    n->left->parent = n;
	    return true;
	}
    }
    else {
	if (n->right)
	    return insert(value, n->right);
	else {
	    n->right = new Node(value);
	    n->right->parent = n;
	    return true;
	}
    }
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if (n) {
	cout << n->info << " ";
	printPreOrder(n->left);
	printPreOrder(n->right);
    }
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    printInOrder(root);
}
void IntBST::printInOrder(Node *n) const {
    // IMPLEMENT HERE

    if(n==nullptr)
    {
      return;
    }

    
    printInOrder(n->left);
    cout<<n->info<<" ";
    printInOrder(n->right);

    
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    printPostOrder(root);
}

void IntBST::printPostOrder(Node *n) const {
    // IMPLEMENT HERE
    if(n==nullptr)
    {
      return;
    }
    printInOrder(n->left);
    
    printInOrder(n->right);
    cout<<n->info<<" ";
}

// return sum of values in tree
int IntBST::sum() const {
    return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    if (n==nullptr)
    {
      return 0;
    }

    
    return sum(n->left) + sum(n->right) + n->info; // REPLACE THIS NON-SOLUTION


}

// return count of values
int IntBST::count() const {
    
    return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const {
    if (n==nullptr)
    {
      return 0;
    }
    return count(n->left) + 1 + count(n->right);// REPLACE THIS NON-SOLUTION
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    if(n==nullptr || n->info==value)
    {
      return n;
    }


    else if (n->info<value)
    {
      return getNodeFor(value, n->right);
    }
    else
    {
      return getNodeFor(value, n->left);
    }

    // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    Node *n = new Node;
    n = getNodeFor(value , root);

    return n!=nullptr; // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    Node*n = getNodeFor(value , root);
    if(n==nullptr)
    {
      return nullptr;
    }
    if (n->parent==nullptr)
    {
      if(!n->left)
      {
        return nullptr;
      }
      n = n->left;
      while(n->right)
      {
        n = n->right;
      }
      return n;

    }
    if(!n->left)
    {
      if(n->info>root->info)
      {
        return n->parent;
      }
      return nullptr;
    }
    else
    {
        n = n->left;
        while(n->right)
        {
          n = n->right;
        }
        return n;

    }
}


// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    Node *n = getPredecessorNode(value);
    if(n==nullptr)
    {
      return 0;
    } // REPLACE THIS NON-SOLUTION
    else{
      return n->info;
    } // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    Node*n = getNodeFor(value , root);
    if(n==nullptr)
    {
      return nullptr;
    }
    if (n->parent==nullptr)
    {
      if(!n->right)
      {
        return nullptr;
      }
      n = n->right;
      while(n->left)
      {
        n = n->left;
      }
      return n;

    }
    if(!n->right)
    {
      if(n->info<root->info)
      {
        return n->parent;
      }
      return nullptr;
    }
    else
    {
        n = n->right;
        while(n->left)
        {
          n = n->left;
        }
        return n;

    }

     // REPLACE THIS NON-SOLUTION
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    Node *n = getSuccessorNode(value);
    if(n==nullptr)
    {
      return 0;
    } // REPLACE THIS NON-SOLUTION
    else{
      return n->info;
    } // REPLACE THIS NON-SOLUTION
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){

  Node *n = getNodeFor(value, root);

  if(n==nullptr)
  {
    return false;
  }

  if (n->parent==nullptr)
  {
    if(n->right)
    {
      if(n->right->info!=getSuccessor(value))
      {
        Node *a = getSuccessorNode(n->info);
        int inf = a->info;
        root->info = inf;
        delete a;
      }
      else
      {
        Node*a = getSuccessorNode(n->info);
        a->parent = nullptr;
        a->left = n->left;
        root = a;

      }
      
    }
    else
    {
      if(n->left->info!=getSuccessor(value))
      {
        Node *a = getPredecessorNode(n->info);
        int inf = a->info;
        root->info = inf;
        delete a;
      }
      else
      {
        Node*a = getPredecessorNode(n->info);
        a->parent = nullptr;
        a->right = n->right;
        root = a;

      }

    }
  }
  else if(n->info < n->parent->info)
  {
    if (getSuccessorNode(value)==nullptr)
    {
      n->parent->left = nullptr;
      return true;
    }
    else if(getSuccessor(value)==n->parent->info)
    {
      if(!n->left)
      {
        n->parent->left = nullptr;
      }
      else
      {
        Node *temp = new Node;
        temp = n->left;
        temp->parent = n->parent;
        n->parent->left = temp;
      }
    }
    else
    {
      Node *temp = new Node;
      temp = getSuccessorNode(value);
      temp->parent = n->parent;

      temp->left = n->left;

      n->parent->right = temp;
    }
  }
  else
  {
    if (getPredecessorNode(value)==nullptr)
    {
      n->parent->right = nullptr;
      return true;
    }
    else if(getPredecessor(value)==n->parent->info)
    {
      if(!n->right)
      {
        n->parent->right = nullptr;
      }
      else
      {
        Node *temp = n->right;
        temp->parent = n->parent;
        n->parent->right = temp;
      }
    }
    else
    {

      Node *temp = getPredecessorNode(value);
      temp->parent = n->parent;

      temp->right = n->right;
      n->parent->right = temp;
    }
  }







  return true;

    
}
