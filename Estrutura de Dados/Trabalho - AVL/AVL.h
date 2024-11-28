class AVL {
    private:
        struct TreeNode {
            int Entry;
            TreeNode* LeftNode;
            TreeNode* RightNode;
            int occur;
            int BalanceFactor;
            int height;
        };
        typedef TreeNode* TreePointer;        
        int count;
    public:
        TreePointer root;
        AVL();
        ~AVL();
        int SetBalanceFactor(TreePointer &raiz);
        int NodeHeight(TreePointer raiz);
        void Insert(TreePointer &raiz, int n);
        void Remove(TreePointer &raiz, int n);
        void BalanceTree(TreePointer &raiz);
        void SimpleRightRotation(TreePointer &raiz);
        void SimpleLeftRotation(TreePointer &raiz);
        void CrescentPrintTree(TreePointer &raiz);
        void DecrescentPrintTree(TreePointer &raiz);
        bool SearchValue(TreePointer &raiz, int n);
        int FindMin(TreePointer &raiz);
        int ValueOccur(TreePointer &raiz, int n);
        int TreeSize(TreePointer &raiz);
        int TreeRoot(TreePointer &raiz);
        bool Empty();
};
