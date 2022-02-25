
// intbst.cpp
// Implements class IntBST
// YOUR NAME(S), DATE

#include "cards.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
Cards::Cards() : root(0) { }

// destructor deletes all nodes
Cards::~Cards() {
    clear(root);
}
bool Cards::empty()
{
  return root == nullptr;
  
}

// recursive helper for destructor
void Cards::clear(Node *n) {
    if (n) {
	clear(n->left);
	clear(n->right);
	delete n;
    }
}

// insert value in tree; return false if duplicate
bool Cards::insert(int value) {
    // handle special case of empty tree first
    if (!root) {
	root = new Node(value);
	return true;
    }
    // otherwise use recursive helper
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
bool Cards::insert(int value, Node *n) {
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
void Cards::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void Cards::printPreOrder(Node *n) const {
    if (n) {
	cout << n->info << " ";
	printPreOrder(n->left);
	printPreOrder(n->right);
    }
}

// print tree data in-order, with helper
void Cards::printInOrder() const {
    printInOrder(root);
}
void Cards::printInOrder(Node *n) const {
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
void Cards::printPostOrder() const {
    printPostOrder(root);
}

void Cards::printPostOrder(Node *n) const {
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
int Cards::sum() const {
    return sum(root);
}

// recursive helper for sum
int Cards::sum(Node *n) const {
    if (n==nullptr)
    {
      return 0;
    }

    
    return sum(n->left) + sum(n->right) + n->info; // REPLACE THIS NON-SOLUTION


}

// return count of values
int Cards::count() const {
    
    return count(root);
}

// recursive helper for count
int Cards::count(Node *n) const {
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
Cards::Node* Cards::getNodeFor(int value, Node* n) const{
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
bool Cards::contains(int value) const {
    Node *n = new Node;
    n = getNodeFor(value , root);

    return n!=nullptr; // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the predecessor of the given value
Cards::Node* Cards::getPredecessorNode(int value) const{
    Node *n = new Node;
    n = getNodeFor(value , root);
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
      bool less = false;
      while(n->parent&&!less)
      {
        n = n->parent;
        if (n->info<value)
        {
          less = true;
        }
      }
      if (n->info>value)
      {
        return nullptr;
      }
      return n;
    }
    else
    {
        n = n->left;
        if(!n->right)
        {
          return n;
        }
        while(n->right)
        {
          n = n->right;
        }
        return n;

    }
}


// returns the predecessor value of the given value or 0 if there is none
int Cards::getPredecessor(int value) const{
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
Cards::Node* Cards::getSuccessorNode(int value) const{
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



    }
    if(!n->right)
    {
        bool greater = false;
        while(n->parent &&!greater)
        {
          n = n->parent;
          if(n->info>value)
          {
            greater = true;
          }

        }
        if(n->info<value)
        {
          return nullptr;
        }
        return n;

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
int Cards::getSuccessor(int value) const{
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


int Cards::min(Node *n)
{

  if(n==nullptr)
  {
    return 0;
  }
  else if (!n->left)
  {
    return n->info;
  }
  else
  {
    return min(n->left);
  }


}
int Cards::min()
{
  return min(root);


}
int Cards::max(Node *n)
{

  if(n==nullptr)
  {
    return 0;
  }
  else if (!n->right)
  {
    return n->info;
  }
  else
  {
    return max(n->right);
  }


}



int Cards::max()
{
  return max(root);
  
}
void Cards::remove(Node* &root, int value)
{
    // base case: the key is not found in the tree
    if (root == nullptr) {
        return;
    }
 
    // if the given key is less than the root node, recur for the left subtree
    if (value < root->info) {
        remove(root->left, value);
    }
 
    // if the given key is more than the root node, recur for the right subtree
    else if (value > root->info) {
        remove(root->right, value);
    }
 
    // key found
    else {
        // Case 1: node to be deleted has no children (it is a leaf node)
        if (root->left == nullptr && root->right == nullptr)
        {
            // deallocate the memory and update root to null
            delete root;
            root = nullptr;
        }
 
        // Case 2: node to be deleted has two children
        else if (root->left && root->right)
        {
            // find its inorder predecessor node
            Node* predecessor = getPredecessorNode(root->info);
 
            // copy value of the predecessor to the current node
            root->info = predecessor->info;
 
            // recursively delete the predecessor. Note that the
            // predecessor will have at most one child (left child)
            remove(root->left, predecessor->info);
        }
 
        // Case 3: node to be deleted has only one child
        else {
            // choose a child node
            //Node* child = (root->left)? root->left: root->right;
            Node* c = new Node;
            if(root->left)
            {
              c = root->left;
            }
            else
            {
              c = root->right;
            }
            Node* n = root;
 
            root = c;
 
            // deallocate the memory
            delete n;
        }
    }
}
void Cards::remove(int value)
{
  remove(root , value);
}



/*
bool IntBST::remove(int value){


    if(root==nullptr)
    {
      return false;
    }
    
    Node *n = getNodeFor(value , root);
    if(n==nullptr)
    {
      delete n;
      return false;
    }
    if(root->info == value && !root->left && !root->right)
    {
      root = nullptr;
      delete n;
      return true;
    }


    

    Node* parent = n->parent;


 


    if (n->left == nullptr && n->right == nullptr)
    {

        if (n->info != root->info)
        {
            if (n->info < parent->info) {
                parent->left = nullptr;
            }
            else {
                parent->right = nullptr;
            }
        }
        else {
            root = nullptr;
        }
      
 
        // deallocate the memory
        delete n;   
        return true;// or delete curr;
    }

    else if (n->left && n->right)
    {

        Node* successor = getSuccessorNode(value);
 

        int temp = successor->info;

        bool b = remove(successor->info);
 

        n->info = temp;
        return true;
    }
 
    else {
      if(n->info==root->info)
      {
        if(n->left)
        {
          root = root->left;
        }
        else
        {
          root = root->right;
        }
      }
      else
      {
        if(n->left&&n->info<parent->info)
        {
          parent->left = n->left;
          
        }
        else if(n->left &&n->info>parent->info)
        {
          parent->right = n->left;
        }
        else if(n->right &&n ->info < parent->info)
        {
          parent->left = n->right;
        }
        else
        {
          parent->right = n->right;
        }
      }
      /*
        Node* sub = new Node;
        if(n->left)
        {
          sub = n->left;
        }
        else
        {
          sub = n->right;
        }

        if (n != root)
        {
            if (n->info < parent->info) {
                parent->left = sub;
            }
            else {
                parent->right = sub;
            }
        }
 

        else {
            root = sub;
        }

      
 
        // deallocate the memory
        
        delete n;
        return true;
    }





    
}
*/
