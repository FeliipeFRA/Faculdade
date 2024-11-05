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
    if (raiz == NULL)
    {
        // criar nó
        TreePointer NewNode = new TreeNode;
        NewNode->Entry = n;
        NewNode->LeftNode = NULL;
        NewNode->RightNode = NULL;
        NewNode->occur = 1;
        raiz = NewNode;
        count++;
    }
    else
    {
        if (n < raiz->Entry)
        {
            Insert(raiz->LeftNode, n);
        }
        else if (n == raiz->Entry)
        {
            raiz->occur++;
            count++;
        }
        else
        {
            Insert(raiz->RightNode, n);
        }
    }
}

void BinaryTree::Remove(TreePointer &raiz, int n)
{
    TreePointer p = raiz;
    if (n == raiz->Entry)
    {
        if (raiz->LeftNode == NULL && raiz->RightNode == NULL)
        {                         // CASO 1-)
            count -= raiz->occur; // remover do count o numero de ocorrencias do no
            delete p;             // deleta o nó
            raiz = NULL;          // aponta raiz pra null, assim left/right node ira pra nulo
            cout << "Numero " << n << " deletado da arvore com sucesso!" << endl;
        }
        else if ((raiz->LeftNode == NULL && raiz->RightNode != NULL) || (raiz->LeftNode != NULL && raiz->RightNode == NULL))
        {
            count -= raiz->occur;         // CASO 2-)
            if (raiz->LeftNode == NULL) { //apontamento do nó filho
                raiz = raiz->RightNode;
            } else {
                raiz = raiz->LeftNode;
            }
            delete p;
            cout << "Numero " << n << " (1 filho) deletado da arvore com sucesso!" << endl;
        }
        else if ((raiz->LeftNode != NULL && raiz->RightNode != NULL)) { // 2 filhos
            if ((raiz->LeftNode->LeftNode == NULL && raiz->LeftNode->RightNode == NULL) || (raiz->RightNode->LeftNode == NULL && raiz->LeftNode->RightNode == NULL)){

            }
        }
        else
        {
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
        cout << raiz->Entry << " [" << raiz->occur << "]" << endl;
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
        cout << raiz->Entry << " [" << raiz->occur << "]" << endl;
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

int BinaryTree::TreeRoot(TreePointer &raiz)
{
    return raiz->Entry;
}

bool BinaryTree::Empty()
{
    return count == 0;
}