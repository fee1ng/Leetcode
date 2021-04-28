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
    //中序遍历
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
    //利用栈做迭代，中序遍历k次返回，不需要遍历整棵树
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