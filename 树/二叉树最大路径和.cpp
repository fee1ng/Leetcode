class Solution {
public:
    int m=INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxgain(root);
        return m;
    }
    int maxgain(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        int left=max(maxgain(root->left),0);
        int right=max(maxgain(root->right),0);
        int path=root->val+left+right;
        m=max(m,path);
        return root->val+max(left,right);
    }
};