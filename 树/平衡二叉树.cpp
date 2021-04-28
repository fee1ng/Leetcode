/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //1.��ǰ�ڵ����������ĸ߶ȣ��жϵ�ǰ�ڵ��Ƿ�ƽ��
    //2.�ݹ���ȡ��ǰ�ڵ�����������Ƿ�ƽ��
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        int l = dfs(root->left);
        int r = dfs(root->right);
        return (abs(l - r) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
    int dfs(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        return 1 + max(l, r);
    }
};