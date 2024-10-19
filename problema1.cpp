//Integrantes:
//1. Olivares Sarmiento, Javier Ignacio Leon
//2. Silva Reyes, Santiago Miguel
//3. Meneses Roncal, Matias Alonso
// C++ implementation of search() and traverse() methods
#include <iostream>
using namespace std;

// A BTree node
class BTreeNode {
    int* keys; //llaves del nodo
    int t; // t es un valor que sirve para saber cuantas llaves se puede tener y cuantos hijos
    BTreeNode** C; //array de punteros que apunta a los hijos del nodo
    int n; //numero actual de claves
    bool leaf; //es hoja o no
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
BTreeNode::BTreeNode(int _t, bool _leaf) // t es un valor que sirve para saber cuantas llaves se puede tener y cuantos hijos
{

    t = _t;
    leaf = _leaf;


    keys = new int[2 * t - 1]; // reserva memoria para 2*t -1 llaves
    C = new BTreeNode*[2 * t]; // 1 mas que el numero de llaves


    n = 0; // inicia con 0 cosas es el array de llaves
}


void BTreeNode::traverse()
{

    int i;
    for (i = 0; i < n; i++) { //recorre hasta el numero de llaves (1 menos porque empieza en 0)

        if (leaf == false) //si no es hoja
            C[i]->traverse(); //recusrividad en C[i] que seria el hijo
        cout << " " << keys[i]; //imprime la key del nodo actual
    }


    if (leaf == false)
        C[i]->traverse();
}

// Function to search key k in subtree rooted with this node
BTreeNode* BTreeNode::search(int k)
{
    int index=0; 

    while (index<n && k > keys[index]){ // el index sea menor al numero de elementos y la llave sea mayor o igual a k
        index++;
    }

    auto * NodoActual =this; //this apunta al objeto actual;
    if(keys[k] == k){ //
        return NodoActual;
    }

    if(leaf){ //si es hoja es decir no podemos bajar mas y lo de arriba no se cumplio, significa que no esta
        return nullptr;
    }

    return C[index]->search(k); //se busca en el hijo

}
