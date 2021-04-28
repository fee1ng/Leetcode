vector<TreeNode*> l;
    void flatten(TreeNode* root) {
        dfs(root);
        for(int i=1;i<l.size();i++)
        {
            TreeNode* pre=l[i-1];
            TreeNode* curr=l[i];
            pre->left=nullptr;
            pre->right=curr;
        }
    }
    void dfs(TreeNode* root)
    {
        if(root==nullptr)
            return;
        l.push_back(root);
        dfs(root->left);
        dfs(root->right);
    }