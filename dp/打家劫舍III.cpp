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
    //当前节点有两种状态，一种选择当前节点，一种不选择当前节点，用两个哈希表key-value对应当前节点选的值和不选的值

    unordered_map<TreeNode*, int> s, ns;
    int res = 0;
    int rob(TreeNode* root) {
        if (root == nullptr)
            return 0;
        dfs(root);
        //return max(s[root],ns[root]);
        return res;
    }
    void dfs(TreeNode* root)
    {
        if (root == nullptr)
            return;
        dfs(root->left);
        dfs(root->right);
        //选择当前节点，两个子节点不能选+root->val
        s[root] = ns[root->left] + ns[root->right] + root->val;
        //不选择当前节点，则左右子节点可选可不选，取两个子节点的最大值相加
        ns[root] = max(s[root->left], ns[root->left]) + max(s[root->right], ns[root->right]);
        //更新最大值
        res = max(res, max(s[root], ns[root]));
    }
};