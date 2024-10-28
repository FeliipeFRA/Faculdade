class BinaryTree{
    private:
        struct TreeNode{
            int Entry;
            TreeNode* LeftNode;
            TreeNode* RightNode;
            int count = 0;
        };
        typedef TreeNode *TreePointer;        
        int count;
    public:
        TreePointer root = NULL;
        BinaryTree();
        ~BinaryTree();
        void Insert(TreePointer raiz, int n);    
};