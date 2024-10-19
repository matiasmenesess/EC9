// C++ implementation of search() and traverse() methods
#include <iostream>
using namespace std;
 
// A BTree node
class BTreeNode {
    int* keys; 
    int t; 
    BTreeNode** C; 
    int n; 
    bool leaf; 
public:
    BTreeNode(int _t, bool _leaf);
 
    
    void traverse();
 
    
    BTreeNode*
    search(int k); 
 
    
    friend class BTree;
};
 
// A BTree
class BTree {
    BTreeNode* root; 
    int t; 
public:
   
    BTree(int _t)
    {
        root = NULL;
        t = _t;
    }
 
    
    void traverse()
    {
        if (root != NULL)
            root->traverse();
    }
 
    
    BTreeNode* search(int k)
    {
        return (root == NULL) ? NULL : root->search(k);
    }
};
 
// Constructor for BTreeNode class
BTreeNode::BTreeNode(int _t, bool _leaf)
{
    
    t = _t;
    leaf = _leaf;
 
    
    keys = new int[2 * t - 1];
    C = new BTreeNode*[2 * t];
 
    
    n = 0;
}
 

void BTreeNode::traverse()
{
   
    int i;
    for (i = 0; i < n; i++) {
       
        if (leaf == false)
            C[i]->traverse();
        cout << " " << keys[i];
    }
 

    if (leaf == false)
        C[i]->traverse();
}
 
// Function to search key k in subtree rooted with this node
BTreeNode* BTreeNode::search(int k)
{
  // YOUR CODE!!!
}
