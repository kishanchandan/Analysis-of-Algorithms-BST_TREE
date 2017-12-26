#include <iostream>
//#include <iomanip>

using namespace std;

#include "BST.h"

//--- Definition of constructor
BST::BST()
: myRoot(0)
{}

bool BST::empty() const
{ return myRoot == 0; }


bool BST::search(const int & item) const
{
   BinNode * locptr = myRoot;
   bool found = false;
   while (!found && locptr != 0)
   {
      if (item < locptr->data)       // descend left
        locptr = locptr->left;
      else if (locptr->data < item)  // descend right
        locptr = locptr->right;
      else                           // item found
        found = true;
   }
   return found;
}


void BST::insert(const int & item)
{
   BinNode * locptr = myRoot;   // search pointer
   BinNode * parent = 0;        // pointer to parent of current node
   bool found = false;     // indicates if item already in BST
   while (!found && locptr != 0)
   {
      parent = locptr;
      if (item < locptr->data)       // descend left
         locptr = locptr->left;
      else if (locptr->data < item)  // descend right
         locptr = locptr->right;
      else                           // item found
         found = true;
   }
   if (!found)
   {                                 // construct node containing item
      locptr = new BinNode(item);  
      if (parent == 0)               // empty tree
         myRoot = locptr;
      else if (item < parent->data )  // insert to left of parent
         parent->left = locptr;
      else                           // insert to right of parent
         parent->right = locptr;
   }
   else
      cout << "Item already in the tree\n";
}


void BST::preOrderRecursion(BinNode* currentnode)const{
    BinNode * locptr = myRoot;   // search pointer
    BinNode * parent = 0; 
    
    if(currentnode!=0){
            cout<<currentnode->data<<"\n";
            preOrderRecursion(currentnode->left);
            //cout<<currentnode->data;
            preOrderRecursion(currentnode->right);
            //cout<<currentnode->data;
    }
    
}
void BST::preOrder()const{
    BinNode * locptr = myRoot;   // search pointer
    BinNode * parent = 0; 
    preOrderRecursion(myRoot);
}

void BST::inOrderRecursion(BinNode* currentnode)const{
    BinNode * locptr = myRoot;   // search pointer
    BinNode * parent = 0; 
    
    if(currentnode!=0){
            inOrderRecursion(currentnode->left);
            cout<<currentnode->data<<"\n";
            
            //cout<<currentnode->data;
            inOrderRecursion(currentnode->right);
            //cout<<currentnode->data;
    }
    
}
void BST::inOrder()const{
    BinNode * locptr = myRoot;   // search pointer
    BinNode * parent = 0; 
    inOrderRecursion(myRoot);
}

int BST::nodecountRecursion(BinNode* currentnode, int totalnodes)const{
    
    if(currentnode==0){
        return 0;
    //cout<<"Node count is"<<totalnodes;
    }
    else{
    totalnodes = 1+nodecountRecursion(currentnode->left,totalnodes)+nodecountRecursion(currentnode->right,totalnodes);    
    return totalnodes;
    }
    
    
    
}
void BST::nodecount()const{
    BinNode * locptr = myRoot;   // search pointer
    BinNode * parent = 0; 
    int totalnodes = 0;
    totalnodes =  nodecountRecursion(myRoot,0);
    cout<<"\nTotal number of nodes is : "<<totalnodes;
}

void BST::deletenode(const int & item)
{
   BinNode * locptr = myRoot;   // search pointer
   BinNode * parent = 0;        // pointer to parent of current node
   bool found = false;     // indicates if item already in BST
   while (!found && locptr != 0)
   {
      
      if (item < locptr->data) {
        parent = locptr;
        locptr = locptr->left;
    }
         
      else if (locptr->data < item){
        parent =locptr;
        locptr = locptr->right;
      
    }
      else{
        cout<<parent->data<<"\n"<<locptr->data;
        found = true;
    }                           // item found
     
   }
   if (!found)
    {                                 // construct node containing item
      cout << "Item Not found in the tree, so deletion is not possible.\n";
    }
    
    if(found){
        
        if(parent==0){
                cout<<"This is root";
            }
        else{
            if(parent->left->data==locptr->data){
                cout<<"Left Child\n";
            
                if(locptr->left==0&&locptr->right==0){
                    cout<<"Node has no children\n";
                    parent->left=0;
                    
                }
                else if(locptr->left==0||locptr->right==0){
                    cout<<"Has one child";
                    if(locptr->left!=0)
                        parent->left=locptr->left;
                    else
                        parent->left=locptr->right;
                }
                else {
                    cout<<"Has two Childs";
                    locptr=locptr->right;
                    BinNode *parenttemp;
                    while(locptr!=0&&locptr->left!=0){
                         parenttemp= locptr;
                        locptr=locptr->left;
                    }
                    
                    cout<<locptr->data;
                    if(locptr->right==0){
                        parent->left->data = locptr->data;
                        parenttemp->left = 0;
                    }
                    else{
                        parent->left->data = locptr->data;
                        parenttemp->left = locptr->right;
                        
                    }
                }
                cout<<"\nIn Order after deletion\n";
                inOrder();
            }
            
            
            else{                                           //Right Child Case
                cout<<"Right Child";
                if(locptr->left==0&&locptr->right==0){
                    cout<<"Node has no children";
                    parent->right=0;
                }
                else if(locptr->left==0||locptr->right==0){
                    cout<<"Has one child";
                    if(locptr->left!=0)
                        parent->right=locptr->left;
                    else
                        parent->right=locptr->right;
                }
                else {
                    cout<<"Has two Childs";
                    cout<<"Data on temp"<<parent->data;
                    cout<<locptr->data;
                    locptr=locptr->right;
                    BinNode *parenttemp;
                    while(locptr!=0&&locptr->left!=0){
                         parenttemp= locptr;
                        locptr=locptr->left;
                    }
                    
                    cout<<locptr->data;
                    if(locptr->right==0){
                        parent->right->data = locptr->data;
                        parenttemp->left = 0;
                    }
                    else{
                        parent->right->data = locptr->data;
                        parenttemp->left = locptr->right;
                        
                    }
                    //locptr->
                    //cout<<parent->right->right->data;
                    
                }
                cout<<"\nIn Order after deletion\n";
                inOrder();
            }
        
        }
    }    
        
        
        
}
    
    
   
