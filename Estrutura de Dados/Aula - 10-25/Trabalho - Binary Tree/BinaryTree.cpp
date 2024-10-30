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
    // criar nó
    TreePointer NewNode = new TreeNode;
    NewNode->Entry = n;
    NewNode->LeftNode = NULL;
    NewNode->RightNode = NULL;
    NewNode->occur = 0;

    // atualizar contadores
    count ++;
    NewNode->occur ++;

    // lógica recursiva
    if (raiz == NULL){
        raiz = NewNode;
    } else {
        if (NewNode->Entry < raiz->Entry){
            Insert(raiz->LeftNode, n);
        } else if (NewNode->Entry == raiz->Entry){
            raiz->occur ++;
        } else {
            Insert(raiz->RightNode, n);
        }
    }
}

void BinaryTree::CrescentPrintTree(TreePointer &raiz){
    if (Empty()){
        cout << "ARVORE VAZIA!" << endl;
    };


    if (raiz == NULL){
        return;
    } else {
        CrescentPrintTree(raiz->LeftNode);
        cout << raiz->Entry << " [" << raiz->occur << "]" << endl;
        CrescentPrintTree(raiz->RightNode);
    }
}

void BinaryTree::DecrescentPrintTree(TreePointer &raiz){
    if (Empty()){
        cout << "ARVORE VAZIA!" << endl;
    };


    if (raiz == NULL){
        return;
    } else {
        DecrescentPrintTree(raiz->RightNode);
        cout << raiz->Entry << " [" << raiz->occur << "]" << endl;
        DecrescentPrintTree(raiz->LeftNode);
    }
}

bool BinaryTree::SearchValue(TreePointer &raiz, int n){
    if (Empty()){
        return false;
    };

    if (raiz == NULL){
        return false;
    } else {
        if (raiz->Entry < n){
            SearchValue(raiz->LeftNode, n);
        } else if (raiz->Entry == n){
            return true;
        } else {
            SearchValue(raiz->LeftNode, n);
        }
    }
}

int BinaryTree::ValueOccur(TreePointer &raiz, int n){
    if (raiz == NULL){
        return 0;
    } else {
        if (raiz->Entry < n){
            SearchValue(raiz->LeftNode, n);
        } else if (raiz->Entry == n){
            return raiz->occur;
        } else {
            SearchValue(raiz->LeftNode, n);
        }
    }
}

bool BinaryTree::Empty(){
    return count == 0;
}