#include "AVL.h"
#include <iostream>
#include <cstdlib>
using namespace std;

AVL::AVL() {
    count = 0;
    root = NULL;
}

AVL::~AVL() {
    ClearTree(root);
}

void AVL::Insert(TreePointer &raiz, int n) {
    if (raiz == NULL) {
        TreePointer NewNode = new TreeNode;
        NewNode->Entry = n;
        NewNode->LeftNode = NULL;
        NewNode->RightNode = NULL;
        NewNode->occur = 1;
        NewNode->BalanceFactor = 0;
        raiz = NewNode;
        count++;
    } else if (n < raiz->Entry) Insert(raiz->LeftNode, n);
    else if (n > raiz->Entry) Insert(raiz->RightNode, n);
    else {
        raiz->occur++;
        count++;
    }

    BalanceTree(raiz);
}

int AVL::SetBalanceFactor(TreePointer &raiz) {
    if (raiz == NULL) return -1;
    return (NodeHeight(raiz->LeftNode) - NodeHeight(raiz->RightNode));
}

int AVL::NodeHeight(TreePointer raiz) {
    if (raiz == NULL) return -1;
    return 1 + max(NodeHeight(raiz->LeftNode), NodeHeight(raiz->RightNode));
}

void AVL::SimpleLeftRotation(TreePointer &raiz) {
    TreePointer temp = raiz->RightNode;
    raiz->RightNode = temp->LeftNode;
    temp->LeftNode = raiz;
    raiz = temp;

    raiz->LeftNode->BalanceFactor = SetBalanceFactor(raiz->LeftNode);
    raiz->BalanceFactor = SetBalanceFactor(raiz);
}

void AVL::SimpleRightRotation(TreePointer &raiz) {
    TreePointer temp = raiz->LeftNode;
    raiz->LeftNode = temp->RightNode;
    temp->RightNode = raiz;
    raiz = temp;

    raiz->RightNode->BalanceFactor = SetBalanceFactor(raiz->RightNode);
    raiz->BalanceFactor = SetBalanceFactor(raiz);
}

void AVL::BalanceTree(TreePointer &raiz) {
    if (raiz == NULL) return;

    raiz->BalanceFactor = SetBalanceFactor(raiz);

    if (raiz->BalanceFactor > 1 && SetBalanceFactor(raiz->LeftNode) >= 0) {
        SimpleRightRotation(raiz);
    } else if (raiz->BalanceFactor < -1 && SetBalanceFactor(raiz->RightNode) <= 0) {
        SimpleLeftRotation(raiz);
    } else if (raiz->BalanceFactor > 1 && SetBalanceFactor(raiz->LeftNode) < 0) {
        SimpleLeftRotation(raiz->LeftNode);
        SimpleRightRotation(raiz);
    } else if (raiz->BalanceFactor < -1 && SetBalanceFactor(raiz->RightNode) > 0) {
        SimpleRightRotation(raiz->RightNode);
        SimpleLeftRotation(raiz);
    }
}

int AVL::FindMin(TreePointer &raiz) {
    if (raiz->LeftNode == NULL) 
        return raiz->Entry;
    return FindMin(raiz->LeftNode);
}

void AVL::Remove(TreePointer &raiz, int n) {
    if (raiz == NULL) return;

    if (n < raiz->Entry) Remove(raiz->LeftNode, n);
    else if (n > raiz->Entry) Remove(raiz->RightNode, n);
    else {
        TreePointer p = raiz;

        if (raiz->LeftNode == NULL && raiz->RightNode == NULL) {
            delete p;
            raiz = NULL;
        } else if (raiz->LeftNode == NULL || raiz->RightNode == NULL) {
            TreePointer tempfilho = (raiz->LeftNode == NULL) ? raiz->RightNode : raiz->LeftNode;
            delete p;
            raiz = tempfilho;
        } else {   
            int min = FindMin(raiz->RightNode);
            raiz->Entry = min;
            Remove(raiz->RightNode, min);
        }
        count--;
    }

    if (raiz != NULL) BalanceTree(raiz);
}

void AVL::CrescentPrintTree(TreePointer &raiz) {
    if (raiz == NULL) return;
    CrescentPrintTree(raiz->LeftNode);
    cout << raiz->Entry << " [" << raiz->occur << "] - (FB: "<< SetBalanceFactor(raiz) << ")" << endl;
    CrescentPrintTree(raiz->RightNode);
}

void AVL::DecrescentPrintTree(TreePointer &raiz) {
    if (raiz == NULL) return;
    DecrescentPrintTree(raiz->RightNode);
    cout << raiz->Entry << " [" << raiz->occur << "]" << endl;
    DecrescentPrintTree(raiz->LeftNode);
}

bool AVL::SearchValue(TreePointer &raiz, int n) {
    if (raiz == NULL) return false;
    if (n == raiz->Entry) return true;
    return (n < raiz->Entry) ? SearchValue(raiz->LeftNode, n) : SearchValue(raiz->RightNode, n);
}

int AVL::ValueOccur(TreePointer &raiz, int n) {
    if (raiz == NULL) return 0;
    if (n == raiz->Entry) return raiz->occur;
    return (n < raiz->Entry) ? ValueOccur(raiz->LeftNode, n) : ValueOccur(raiz->RightNode, n);
}

int AVL::TreeSize(TreePointer &raiz) {
    return count;
}

int AVL::TreeRoot(TreePointer &raiz) {
    return raiz->Entry;
}

bool AVL::Empty() {
    return count == 0;
}

void AVL::ClearTree(TreePointer &raiz) {
    if (raiz == NULL) return;
    ClearTree(raiz->LeftNode);
    ClearTree(raiz->RightNode);
    delete raiz;
    raiz = NULL;
}
