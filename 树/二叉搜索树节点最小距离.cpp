//中序遍历得到排好序的数组
//计算相邻数据的最小差值

vector<int> tmp;
    int minDiffInBST(TreeNode* root) {
        int min=0x3f3f3f3f;
        dfs(root);
        for(int i=0;i<tmp.size()-1;i++)
            if(min>tmp[i+1]-tmp[i])
                min=tmp[i+1]-tmp[i];
        return min;
    }
    void dfs(TreeNode* root)
    {
        if(root==nullptr)
            return;
        dfs(root->left);
        tmp.push_back(root->val);
        dfs(root->right);
    }