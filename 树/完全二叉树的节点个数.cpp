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
//层序遍历
class Solution {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*> q;
        if (root == nullptr)
            return 0;
        q.push(root);
        int res = 0;
        while (!q.empty())
        {
            int size = q.size();
            res += q.size();
            while (size--)
            {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left != nullptr)
                    q.push(curr->left);
                if (curr->right != nullptr)
                    q.push(curr->right);
            }
        }
        return res;
    }
};


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
//深度优先+完全二叉树的性质
class Solution {
public:
    int res = 0;
    int countNodes(TreeNode* root) {
        dfs(root);
        return res;
    }
    void dfs(TreeNode* root)
    {
        if (root == nullptr)
            return;
        res++;
        if (root->left == nullptr)
            return;
        else
            dfs(root->left);
        if (root->right == nullptr)
            return;
        else
            dfs(root->right);
    }
};