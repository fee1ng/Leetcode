class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return dfs(root,root);
    }
    bool dfs(TreeNode* left,TreeNode* right)
    {
        if(left==NULL&&right==NULL)
            return true;
        if(left==NULL||right==NULL)
            return false;
        if(left->val!=right->val)
            return false;
        return dfs(left->left,right->right)&&dfs(left->right,right->left);
    }
};