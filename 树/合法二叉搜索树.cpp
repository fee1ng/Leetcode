//中序遍历验证数组是否有序

vector<int> v;
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)
            return true;
        inorder(root);
        for(int i=0;i<v.size();i++)
            for(int j=i+1;j<v.size();j++)
            {
                if(v[i]>=v[j])
                    return false;
            }
        return true;
    }
    void inorder(TreeNode* root)
    {
        if(root==nullptr)
            return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }