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
        void CrescentPrintTree(TreePointer &raiz);
        void DecrescentPrintTree(TreePointer &raiz);
        bool SearchValue(TreePointer &raiz, int n);
        int ValueOccur(TreePointer &raiz, int n);
        bool Empty();
};