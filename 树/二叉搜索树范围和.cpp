  int rangeSumBST(TreeNode* root, int L, int R) {
        int sum=0;
        if(root==nullptr)
            return 0;
        if(root->val<=R&&root->val>=L)
            sum+=root->val;
        sum+=rangeSumBST(root->left,L,R);
        sum+=rangeSumBST(root->right,L,R);
        return sum;
    }