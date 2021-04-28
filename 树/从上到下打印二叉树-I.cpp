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
    //≤„–Ú±È¿˙
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if (root == nullptr)
            return res;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left != nullptr)
                    q.push(curr->left);
                if (curr->right != nullptr)
                    q.push(curr->right);
                res.emplace_back(curr->val);
            }
        }
        return res;
    }
};