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
    //之字形打印，按层数是奇数还是偶数分类讨论
    //奇数层从左至右打印，偶数层从右至左打印，故需要一个栈存储每一层的节点
    //奇数层让左子树先入栈，则出栈时右子树先出栈，则在偶数层右子树可以先打印，反之同理
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        stack<TreeNode*> q;
        if (root == nullptr)
            return res;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            int size = q.size();
            level++;
            vector<int> v;
            vector<TreeNode*> node;
            while (size--)
            {
                TreeNode* curr = q.top();
                q.pop();
                //偶数层先进右子树
                if (level % 2 == 0)
                {
                    v.push_back(curr->val);
                    if (curr->right != nullptr)
                        //q.push(curr->right);
                        node.push_back(curr->right);
                    if (curr->left != nullptr)
                        //q.push(curr->left);
                        node.push_back(curr->left);
                }
                //奇数层则先进左子树
                else
                {
                    v.push_back(curr->val);
                    if (curr->left != nullptr)
                        //q.push(curr->left);
                        node.push_back(curr->left);
                    if (curr->right != nullptr)
                        //q.push(curr->right);
                        node.push_back(curr->right);
                }
            }
            if (v.size() != 0)
                res.push_back(v);
            //统一入栈下一层节点
            for (auto n : node)
                q.push(n);
        }
        return res;
    }
};