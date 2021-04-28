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
    //1.求当前节点左右子树的高度，判断当前节点是否平衡
    //2.递归求取当前节点的左右子树是否平衡
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