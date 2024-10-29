class BinaryTree{
    private:
        struct TreeNode{
            int Entry;
            TreeNode* LeftNode;
            TreeNode* RightNode;
            int occur = 0;
        };
        typedef TreeNode *TreePointer;        
        int count = 0;
    public:
        TreePointer root;
        BinaryTree();
        ~BinaryTree();
        void Insert(TreePointer &raiz, int n);
        void PrintTree(TreePointer &raiz);
};