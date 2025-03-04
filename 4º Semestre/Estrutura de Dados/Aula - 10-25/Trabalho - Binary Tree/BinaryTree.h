class BinaryTree{
    private:
        struct TreeNode{
            int Entry;
            TreeNode* LeftNode;
            TreeNode* RightNode;
            int occur;
        };
        typedef TreeNode *TreePointer;        
        int count;
    public:
        TreePointer root;
        BinaryTree();
        ~BinaryTree();
        void Insert(TreePointer &raiz, int n);
        void Remove(TreePointer &raiz, int n);
        void CrescentPrintTree(TreePointer &raiz);
        void DecrescentPrintTree(TreePointer &raiz);
        bool SearchValue(TreePointer &raiz, int n);
        int FindMin(TreePointer &raiz);
        int ValueOccur(TreePointer &raiz, int n);
        int TreeSize(TreePointer &raiz);
        int TreeRoot(TreePointer &raiz);
        bool Empty();
};