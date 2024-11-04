#include "BinaryTree.h"
#include <iostream>
#include <cstdlib>
using namespace std;

BinaryTree::BinaryTree()
{
    count = 0;
    height = 1;
    root = NULL;
}

BinaryTree::~BinaryTree()
{
}

void BinaryTree::Insert(TreePointer &raiz, int n)
{
    // lógica recursiva
    if (raiz == NULL)
    {
        // criar nó
        TreePointer NewNode = new TreeNode;
        NewNode->Entry = n;
        NewNode->LeftNode = NULL;
        NewNode->RightNode = NULL;
        NewNode->occur = 1;
        NewNode->level = 0;
        raiz = NewNode;
        count++;
    }
    else
    {
        if (n < raiz->Entry)
        {
            Insert(raiz->LeftNode, n);
            raiz->LeftNode->level = raiz->level + 1;
            if (raiz->LeftNode->level >= height)
            {
                height = raiz->LeftNode->level + 1;
            }
        }
        else if (n == raiz->Entry)
        {
            raiz->occur++;
            count++;
        }
        else
        {
            Insert(raiz->RightNode, n);
            raiz->RightNode->level = raiz->level + 1;
            if (raiz->RightNode->level >= height)
            {
                height = raiz->RightNode->level + 1;
            }
        }
    }
}

void BinaryTree::Remove(TreePointer &raiz, int n)
{
    TreePointer p = raiz;
    if (n == raiz->Entry)
    {
        if (raiz->LeftNode == NULL && raiz->RightNode == NULL){
            p == NULL;
            delete raiz;
            cout << "Numero " << n << " deletado da arvore com sucesso!" << endl;
        } else {
            cout << "NAO E POSSIVEL REMOVER ESSE NUMERO" << endl;
        }
    }
    else
    {
        if (n < raiz->Entry)
        {
            Remove(raiz->LeftNode, n);
        }
        else
        {
            Remove(raiz->RightNode, n);
        }
    };
}

void BinaryTree::CrescentPrintTree(TreePointer &raiz)
{
    if (Empty())
    {
        cout << "ARVORE VAZIA!" << endl;
    };

    if (raiz == NULL)
    {
        return;
    }
    else
    {
        CrescentPrintTree(raiz->LeftNode);
        cout << raiz->Entry << " [" << raiz->occur << "] - Nivel: " << raiz->level << endl;
        CrescentPrintTree(raiz->RightNode);
    }
}

void BinaryTree::DecrescentPrintTree(TreePointer &raiz)
{
    if (Empty())
    {
        cout << "ARVORE VAZIA!" << endl;
    };

    if (raiz == NULL)
    {
        return;
    }
    else
    {
        DecrescentPrintTree(raiz->RightNode);
        cout << raiz->Entry << " [" << raiz->occur << "] - Nivel: " << raiz->level << endl;
        DecrescentPrintTree(raiz->LeftNode);
    }
}

bool BinaryTree::SearchValue(TreePointer &raiz, int n)
{
    // ordem importante, primeiro verificar se é NULL, se verificar ENTRY primeiro da ruim pois
    if (raiz == NULL)
    {
        return false;
    }
    if (n == raiz->Entry)
    {
        return true;
    }
    else
    {
        if (n < raiz->Entry)
        {
            SearchValue(raiz->LeftNode, n);
        }
        else
        {
            SearchValue(raiz->RightNode, n);
        }
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

int BinaryTree::TreeHeight(TreePointer &raiz)
{
    return height;
}

int BinaryTree::TreeRoot(TreePointer &raiz)
{
    return raiz->Entry;
}

bool BinaryTree::Empty()
{
    return count == 0;
}