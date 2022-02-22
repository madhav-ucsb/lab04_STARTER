
// intbst.cpp
// Implements class IntBST
// YOUR NAME(S), DATE

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
template <class T>
IntBST<T>::IntBST() : root(NULL) { }

// destructor deletes all nodes
template <class T>
IntBST<T>::~IntBST() {
    clear(root);
}

// recursive helper for destructor
template <class T>
void IntBST<T>::clear(Node *n) {
    if (n) {
	clear(n->left);
	clear(n->right);
	delete n;
    }
}

// insert value in tree; return false if duplicate
template <class T>
bool IntBST<T>::insert(T value) {
    // handle special case of empty tree first
    if (!root) {
	root = new Node(value);
	return true;
    }
    // otherwise use recursive helper
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
template <class T>
bool IntBST<T>::insert(T value, Node *n) {
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
template <class T>
void IntBST<T>::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
template <class T>
void IntBST<T>::printPreOrder(Node *n) const {
    if (n) {
	cout << n->info << " ";
	printPreOrder(n->left);
	printPreOrder(n->right);
    }
}

// print tree data in-order, with helper
template <class T>
void IntBST<T>::printInOrder() const {
    printInOrder(root);
}
template <class T>
void IntBST<T>::printInOrder(Node *n) const {
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
template <class T>
void IntBST<T>::printPostOrder() const {
    printPostOrder(root);
}
template <class T>
void IntBST<T>::printPostOrder(Node *n) const {
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


// return count of values
template <class T>
int IntBST<T>::count() const {
    
    return count(root);
}

// recursive helper for count
template <class T>
int IntBST<T>::count(Node *n) const {
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
template <class T>
typename IntBST<T>::Node* IntBST<T>::getNodeFor(T value, Node* n) const{
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
template <class T>
bool IntBST<T>::contains(T value) const {
    Node *n = NULL;
    n = getNodeFor(value , root);

    return n!=nullptr; // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the predecessor of the given value
template <class T>
typename IntBST<T>::Node* IntBST<T>::getPredecessorNode(T value) const{
    Node *n = nullptr;
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
template <class T>
T IntBST<T>::getPredecessor(T value) const{
    Node *n = getPredecessorNode(value);
    if(n==nullptr)
    {
      return (T) 0;
    } // REPLACE THIS NON-SOLUTION
    else{
      return n->info;
    } // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the successor of the given value
template <class T>
typename IntBST<T>::Node* IntBST<T>::getSuccessorNode(T value) const{
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
template <class T>
T IntBST<T>::getSuccessor(T value) const{
    Node *n = getSuccessorNode(value);
    if(n==nullptr)
    {
      return (T) 0;
    } // REPLACE THIS NON-SOLUTION
    else{
      return n->info;
    } // REPLACE THIS NON-SOLUTION
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
template <class T>
bool IntBST<T>::remove(T value){
  printInOrder();
  cout<<endl;
  if (root==nullptr)
  {
    return false;
  }

  if (getNodeFor(value,root)==nullptr)
  {
    return false;
  }
  if (value == root->info)
  {
    cout<<"Came in to for loop"<<endl;
    Node *n = nullptr;
    if(!root->right && !root->left)
    {
      root = nullptr;
      return true;

    }
    if(root->right)
    {
      cout<<"In the zone"<<endl;
      Node *n =  getSuccessorNode(value);
      cout<<"start worked"<<endl;
      root->info = n->info;
      cout<<"this worked"<<endl;
      n->parent->left = nullptr;
      cout<<"that worked"<<endl;
      if(n->right)
      {
        n->parent->left = n->right;
        cout<<"lefting"<<endl;
      }
      return true;
    }



  }

  Node *a = getNodeFor(value , root);

  Node*b = getSuccessorNode(value);

  Node *c = getPredecessorNode(value);

  Node *p = a->parent;
  if(a->right && a->left && a->parent)
  {
    if (a->parent->info>value)
    {
      T temp = b->info;

      b->parent->left = b->left;
      a->info = temp;



    }
    else{
      T temp = c->info;

      c->parent->right = b->right;
      a->info = temp;

    }
    return true;

  }
  else if (!a->right && !a->left)
  {
    delete a;

    return true;
  }

  else if(a->right)
  {
    Node*temp = a->parent;

    a = a->right;
    a->parent = temp;
    return true;
  }
  else if(a->left)
  {
    Node*temp = a->parent;

    a = a->left;
    a->parent = temp;
    return true;
  }
  else
  {
    return true;
  }


  /*
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
        a->right = n->left;
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

      temp->right = n->right;

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
        //Node *temp = n->right;
        //temp->parent = n->parent;
        n = n->right;
        n->parent = n->parent->parent;
        n->parent->right = n;
        //n->parent->right = temp;
      }
    }
    else
    {

      Node *temp = getPredecessorNode(value);
      temp->parent = n->parent;

      temp->left = n->left;
      n->parent->right = temp;
    }
    */
  }







    

