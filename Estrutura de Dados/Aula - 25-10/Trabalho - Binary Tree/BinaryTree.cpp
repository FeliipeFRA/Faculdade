#include "BinaryTree.h"
#include <iostream>
#include <cstdlib>
using namespace std;

BinaryTree::BinaryTree(){
    
}

BinaryTree::~BinaryTree(){

}

void BinaryTree::Insert(TreePointer raiz, int n){
    if (raiz == NULL){
        raiz->Entry = n;
        raiz->count ++;
        return;
    }
    
}