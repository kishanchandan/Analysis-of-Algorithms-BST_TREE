#include <iostream>
using namespace std;  

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST
{
 public:
  /***** Function Members *****/
  BST();
  bool empty() const;
  bool search(const int & item) const; 
  void insert(const int & item);
  void deletenode(const int & item);
  void preOrder()const;
  void inOrder()const;
  void nodecount()const;
  
  
 private:

  /***** Node class *****/
  class BinNode 
  {
    
    public:
      
    int data;
    BinNode * left;
    BinNode * right;

    // BinNode constructors
    // Default -- data part is default int value; both links are null.
    BinNode()
    : left(0), right(0)
    {}

    // Explicit Value -- data part contains item; both links are null.
    BinNode(int item)
    : data(item), left(0), right(0)
    {}
 
  };// end of class BinNode declaration
  
  /***** Data Members *****/
  BinNode * myRoot; 
  void preOrderRecursion(BinNode* node)const;
  void inOrderRecursion(BinNode* node)const;
  int nodecountRecursion(BinNode* node,int totalnodes)const;
}; // end of class declaration

#endif
