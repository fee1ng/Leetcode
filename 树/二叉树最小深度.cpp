 int minDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        //当到达叶子节点时，初始高度为1
        if(root->left==NULL&&root->right==NULL)
            return 1;
        //计算左子树和右子树的高度
        int l=minDepth(root->left);
        int r=minDepth(root->right);
        //若左子树或右子树有一个为空另一个不为空，则返回不为空那个的高度+1
        if(root->left==NULL||root->right==NULL)
            return max(l,r)+1;
        //此时左子树和右子树都不为空，返回高度较小者+1
        return min(l,r)+1;
    }