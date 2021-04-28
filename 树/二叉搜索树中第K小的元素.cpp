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
    vector<int> v;
    //�������
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        return v[k - 1];
    }
    void dfs(TreeNode* root)
    {
        if (root == nullptr)
            return;
        dfs(root->left);
        v.push_back(root->val);
        dfs(root->right);
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
class Solution {
public:
    //����ջ���������������k�η��أ�����Ҫ����������
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        while (1)
        {
            while (root != nullptr)
            {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (--k == 0)
                return root->val;
            root = root->right;

        }
    }
};