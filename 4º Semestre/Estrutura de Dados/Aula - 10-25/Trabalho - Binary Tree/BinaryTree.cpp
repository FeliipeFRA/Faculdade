#include "BinaryTree.h"
#include <iostream>
#include <cstdlib>
using namespace std;

BinaryTree::BinaryTree()
{
    count = 0;
    root = NULL;
}

BinaryTree::~BinaryTree()
{
}

void BinaryTree::Insert(TreePointer &raiz, int n)
{
    // lógica recursiva
    if (raiz == NULL) {
        // criar nó
        TreePointer NewNode = new TreeNode;
        NewNode->Entry = n;
        NewNode->LeftNode = NULL;
        NewNode->RightNode = NULL;
        NewNode->occur = 1;
        raiz = NewNode;
        count++;
    }
    else if (n < raiz->Entry) Insert(raiz->LeftNode, n);
    else if (n > raiz->Entry) Insert(raiz->RightNode, n);
    else {
        raiz->occur++;
        count++;
    }
}

int BinaryTree::FindMin(TreePointer &raiz) {
    int min = raiz->Entry;
    if (raiz->LeftNode == NULL) return min;
    else FindMin(raiz->LeftNode);
};

void BinaryTree::Remove(TreePointer &raiz, int n)
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

void BinaryTree::CrescentPrintTree(TreePointer &raiz)
{
    if (Empty()) cout << "ARVORE VAZIA!" << endl;
    if (raiz == NULL) return;
    else {
        CrescentPrintTree(raiz->LeftNode);
        cout << raiz->Entry << " [" << raiz->occur << "]" << endl;
        CrescentPrintTree(raiz->RightNode);
    }
}

void BinaryTree::DecrescentPrintTree(TreePointer &raiz)
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

bool BinaryTree::SearchValue(TreePointer &raiz, int n)
{
    // ordem importante, primeiro verificar se é NULL, se verificar ENTRY primeiro da ruim
    if (raiz == NULL) return false;
    if (n == raiz->Entry) return true;
    else {
        if (n < raiz->Entry) SearchValue(raiz->LeftNode, n);
        else  SearchValue(raiz->RightNode, n);
    }
}

int BinaryTree::ValueOccur(TreePointer &raiz, int n)
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

int BinaryTree::TreeSize(TreePointer &raiz)
{
    return count;
}

int BinaryTree::TreeRoot(TreePointer &raiz)
{
    return raiz->Entry;
}

bool BinaryTree::Empty()
{
    return count == 0;
}