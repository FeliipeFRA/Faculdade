class BinaryTree{
    private:
        struct TreeNode{
            int Entry;
            TreeNode* LeftNode;
            TreeNode* RightNode;
            int occur;
            int level;
        };
        typedef TreeNode *TreePointer;        
        int count;
        int height;
    public:
        TreePointer root;
        BinaryTree();
        ~BinaryTree();
        void Insert(TreePointer &raiz, int n);
        void CrescentPrintTree(TreePointer &raiz);
        void DecrescentPrintTree(TreePointer &raiz);
        bool SearchValue(TreePointer &raiz, int n);
        int ValueOccur(TreePointer &raiz, int n);
        int TreeSize(TreePointer &raiz);
        int TreeHeight(TreePointer &raiz);
        int TreeRoot(TreePointer &raiz);
        bool Empty();
};