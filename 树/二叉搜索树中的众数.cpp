  vector<int> v;
    vector<int> res;
    vector<int> findMode(TreeNode* root) {
        if(root==nullptr)
            return res;
        dfs(root);
        int max=1;
        int cur=1;
        res.push_back(v[0]);
        for(int i=1;i<v.size();i++)
        {
            if(v[i]!=v[i-1])
                cur=1;
            else
                cur++;
            if(cur==max)
                res.push_back(v[i]);
            else if(cur>max)
            {
                res.clear();
                max=cur;
                res.push_back(v[i]);
            }
        }
        return res;
    }
    void  dfs(TreeNode* root)
    {
        if(root==nullptr)
            return;
        dfs(root->left);
        v.push_back(root->val);
        dfs(root->right);
    }