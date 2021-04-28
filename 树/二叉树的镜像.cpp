/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //交换每一个根节点的左右子节点,做一个前序遍历
    TreeNode* mirrorTree(TreeNode* root) {
        dfs(root);
        return root;
    }
    void dfs(TreeNode* root)
    {
        if (root == nullptr)
            return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        dfs(root->left);
        dfs(root->right);
    }
};