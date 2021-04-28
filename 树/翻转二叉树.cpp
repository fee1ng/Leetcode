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
    //��ջ���в���������ȴ洢���󽻻������ӽڵ�
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return root;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty())
        {
            int size = s.size();
            vector<TreeNode*> v;
            while (size--)
            {
                TreeNode* curr = s.top();
                s.pop();
                if (curr->left != nullptr)
                    v.push_back(curr->left);
                if (curr->right != nullptr)
                    v.push_back(curr->right);
                TreeNode* temp = curr->left;
                curr->left = curr->right;
                curr->right = temp;
            }
            for (auto& n : v)
                s.push(n);
        }
        return root;
    }
};