#include "BinaryTree.h"
#include <iostream>
#include <cstdlib>
using namespace std;

BinaryTree::BinaryTree(){
    count = 0;
    root = NULL;
}

BinaryTree::~BinaryTree(){

}

void BinaryTree::Insert(TreePointer &raiz, int n){
    TreePointer NewNode = new TreeNode;
    NewNode->Entry = n;
    NewNode->LeftNode = nullptr;
    NewNode->RightNode = nullptr;
    count ++;
    NewNode->occur ++;
    if (raiz == nullptr){
        raiz = NewNode;
    };
    if (NewNode->Entry < raiz->Entry){
        Insert(raiz->LeftNode, n);
    } else {
        Insert(raiz->RightNode, n);
    }
}

void BinaryTree::PrintRoot(TreePointer &raiz){
    cout << raiz->Entry << endl;
}