#include "AVL.h"
#include <iostream>
#include <cstdlib>
using namespace std;

AVL::AVL()
{
    count = 0;
    root = NULL;
}

AVL::~AVL()
{
}

void AVL::Insert(TreePointer &raiz, int n)
{
    // lógica recursiva
    if (raiz == NULL) {
        // criar nó
        TreePointer NewNode = new TreeNode;
        NewNode->Entry = n;
        NewNode->LeftNode = NULL;
        NewNode->RightNode = NULL;
        NewNode->occur = 1;
        NewNode->BalanceFactor = 0;
        raiz = NewNode;
        count++;
    }
    else if (n < raiz->Entry) Insert(raiz->LeftNode, n);
    else if (n > raiz->Entry) Insert(raiz->RightNode, n);
    else {
        raiz->occur++;
        count++;
    }

    BalanceTree(raiz);
}

int AVL::SetBalanceFactor(TreePointer &raiz){
 if (raiz == NULL){
    return -1;
 }
 return (NodeHeight(raiz->LeftNode) - NodeHeight(raiz->RightNode));
}

int AVL::NodeHeight(TreePointer raiz){
    if (raiz == NULL){
        return -1;
    }
    return 1 + max(NodeHeight(raiz->LeftNode), NodeHeight(raiz->RightNode));
}

void AVL::SimpleLeftRotation(TreePointer &raiz){
    TreePointer temp = raiz->RightNode;
    raiz->RightNode = temp->LeftNode;
    temp->LeftNode = raiz;
    raiz = temp;

    raiz->LeftNode->BalanceFactor = SetBalanceFactor(raiz->LeftNode);
    raiz->BalanceFactor = SetBalanceFactor(raiz);
}

void AVL::SimpleRightRotation(TreePointer &raiz){
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
        SimpleRightRotation(raiz); // CASO 1-) SIMPLES
    }
    else if (raiz->BalanceFactor < -1 && SetBalanceFactor(raiz->RightNode) <= 0) {
        SimpleLeftRotation(raiz); // CASO 2-) SIMPLES
    }
    else if (raiz->BalanceFactor > 1 && SetBalanceFactor(raiz->LeftNode) < 0) {
        SimpleLeftRotation(raiz->LeftNode); 
        SimpleRightRotation(raiz); // CASO 3-) DUPLA         
    }
    else if (raiz->BalanceFactor < -1 && SetBalanceFactor(raiz->RightNode) > 0) {
        SimpleRightRotation(raiz->RightNode); 
        SimpleLeftRotation(raiz); // CASO 4-) DUPLA
    }
}


int AVL::FindMin(TreePointer &raiz) {
    if (raiz->LeftNode == NULL) 
        return raiz->Entry;
    return FindMin(raiz->LeftNode);
};

void AVL::Remove(TreePointer &raiz, int n)
{
    if (n < raiz->Entry)
        Remove(raiz->LeftNode, n);
    else if (n > raiz->Entry)
        Remove(raiz->RightNode, n);
    if (n == raiz->Entry){
        TreePointer p = raiz; // ponteiro auxiliar

        if (raiz->LeftNode == NULL && raiz->RightNode == NULL) { // CASO 1-)
            delete p;
            raiz = NULL;
        }
        else if ((raiz->LeftNode == NULL && raiz->RightNode != NULL) || (raiz->LeftNode != NULL && raiz->RightNode == NULL)) // CASO 2-)
        {
            TreePointer tempfilho;
            if (raiz->LeftNode == NULL) tempfilho = raiz->RightNode;
            else tempfilho = raiz->LeftNode;
            delete p;
            raiz = tempfilho;
        }
        else {   
            int min = FindMin(raiz->RightNode);
            raiz->Entry = min;
            Remove(raiz->RightNode, min);
        }
    }
}

void AVL::CrescentPrintTree(TreePointer &raiz)
{
    if (Empty()) cout << "ARVORE VAZIA!" << endl;
    if (raiz == NULL) return;
    else {
        CrescentPrintTree(raiz->LeftNode);
        cout << raiz->Entry << " [" << raiz->occur << "] - (FB: "<< SetBalanceFactor(raiz) << ")" << endl;
        CrescentPrintTree(raiz->RightNode);
    }
}

void AVL::DecrescentPrintTree(TreePointer &raiz)
{
    if (Empty()) cout << "ARVORE VAZIA!" << endl;
    if (raiz == NULL) return;
    else
    {
        DecrescentPrintTree(raiz->RightNode);
        cout << raiz->Entry << " [" << raiz->occur << "]" << endl;
        DecrescentPrintTree(raiz->LeftNode);
    }
}

bool AVL::SearchValue(TreePointer &raiz, int n)
{
    // ordem importante, primeiro verificar se é NULL, se verificar ENTRY primeiro da ruim
    if (raiz == NULL) return false;
    if (n == raiz->Entry) return true;
    else {
        if (n < raiz->Entry) SearchValue(raiz->LeftNode, n);
        else  SearchValue(raiz->RightNode, n);
    }
}

int AVL::ValueOccur(TreePointer &raiz, int n)
{
    if (raiz == NULL)
    {
        return 0;
    }
    if (n == raiz->Entry)
    {
        return raiz->occur;
    }
    else
    {
        if (n < raiz->Entry)
        {
            ValueOccur(raiz->LeftNode, n);
        }
        else
        {
            ValueOccur(raiz->RightNode, n);
        }
    }
}

int AVL::TreeSize(TreePointer &raiz)
{
    return count;
}

int AVL::TreeRoot(TreePointer &raiz)
{
    return raiz->Entry;
}

bool AVL::Empty()
{
    return count == 0;
}