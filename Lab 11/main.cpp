#include <iostream>
#include "bintree.h"
#include <cstdlib>
#include <string>

using namespace main_savitch_10;
int main() {

    binary_tree_node <char>* M = new binary_tree_node<char>('M');
    binary_tree_node <char>* H = new binary_tree_node<char>('H');
    binary_tree_node <char>* T = new binary_tree_node<char>('T');
    binary_tree_node <char>* E = new binary_tree_node<char>('E');
    binary_tree_node <char>* P = new binary_tree_node<char>('P');
    binary_tree_node <char>* W = new binary_tree_node<char>('W');
    binary_tree_node <char>* A = new binary_tree_node<char>('A');
    binary_tree_node <char>* Q = new binary_tree_node<char>('Q');

    //Null Nodes
    binary_tree_node <char>* NULL1 = new binary_tree_node<char>('N');//used
    binary_tree_node <char>* NULL2 = new binary_tree_node<char>('N');//used
    binary_tree_node <char>* NULL3 = new binary_tree_node<char>('N');//used
    binary_tree_node <char>* NULL4 = new binary_tree_node<char>('N');//used
    binary_tree_node <char>* NULL5 = new binary_tree_node<char>('N');//used
    binary_tree_node <char>* NULL6 = new binary_tree_node<char>('N');//used
    binary_tree_node <char>* NULL7 = new binary_tree_node<char>('N');//used


//    binary_tree_node <char>* NULL8 = new binary_tree_node<char>(NULL);
//    binary_tree_node <char>* NULL9 = new binary_tree_node<char>(NULL);


    M->set_left(H);
    M->set_right(T);

    H->set_left(E);
    H->set_right(NULL1);

    NULL1->set_left(NULL2);
    NULL1->set_left(NULL3);

    E->set_left(A);
    E->set_right(NULL4);

    T->set_left(P);
    T->set_right(W);

    P->set_left(NULL5);
    P->set_right(Q);

    W->set_left(NULL6);
    W->set_right(NULL7);

    cout<<M->data() << endl;
    cout<<H->data() << " " << T->data() << endl;
    cout<<E->data() << " " << "NULL" << " " << P->data() << " " << W->data() << endl;
    cout<<A->data() << " NULL NULL NULL " << Q->data() << " NULL NULL";
display_complete_tree(M);


    return 0;
}