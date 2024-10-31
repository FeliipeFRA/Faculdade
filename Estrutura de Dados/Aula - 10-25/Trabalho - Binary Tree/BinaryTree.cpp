#include "BinaryTree.h"
#include <iostream>
#include <cstdlib>
using namespace std;

BinaryTree::BinaryTree(){
    count = 0;
    height = 1;
    root = NULL;
}

BinaryTree::~BinaryTree(){

}

void BinaryTree::Insert(TreePointer &raiz, int n){
    // criar nó - PERGUNTAR SOBRE REPETIÇÃO DE NEW
    TreePointer NewNode = new TreeNode;
    NewNode->Entry = n;
    NewNode->LeftNode = NULL;
    NewNode->RightNode = NULL;
    NewNode->occur = 1;
    NewNode->level = 0;


    // lógica recursiva
    if (raiz == NULL){
        raiz = NewNode;
        count ++;
    } else {
        if (NewNode->Entry < raiz->Entry){
            Insert(raiz->LeftNode, n);
            raiz->LeftNode->level = raiz->level + 1;
            if (raiz->LeftNode->level >= height) {
                height = raiz->LeftNode->level + 1;
            }
        } else if (NewNode->Entry == raiz->Entry){
            raiz->occur ++;
            count ++;
        } else {
            Insert(raiz->RightNode, n);
            raiz->RightNode->level = raiz->level + 1;
            if (raiz->RightNode->level >= height) {
                height = raiz->RightNode->level + 1;
            }
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
        cout << raiz->Entry << " [" << raiz->occur << "] - Nivel: " << raiz->level << endl;
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

int BinaryTree::TreeSize(TreePointer &raiz){
    return count;
}

int BinaryTree::TreeHeight(TreePointer &raiz){
    return height;
}

int BinaryTree::TreeRoot(TreePointer &raiz){
    return raiz->Entry;
}

bool BinaryTree::Empty(){
    return count == 0;
}