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
    //与之前的节点相比，如果小于等于返回错误
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        if (!isValidBST(root->left))
            return false;
        if (pre != nullptr && root->val <= pre->val)
            return false;
        pre = root;
        if (!isValidBST(root->right))
            return false;
        return true;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//记住当前子树的最大值与最小值，作比较
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return help(root, LONG_MAX, LONG_MIN);

    }
    bool help(TreeNode* root, long max, long min)
    {
        if (root == nullptr)
            return true;
        if (root->val <= min)
            return false;
        if (root->val >= max)
            return false;
        return help(root->left, root->val, min) && help(root->right, max, root->val);
    }
};

//暴力法验证中序遍历数组的有序性
class Solution {
public:
    vector<int> v;
    bool isValidBST(TreeNode* root) {
        help(root);
        int n = v.size();
        for (int i = 0;i < n;i++)
        {
            for (int j = i + 1;j < n;j++)
            {
                if (v[i] >= v[j])
                    return false;
            }
        }
        return true;
    }
    void help(TreeNode* root)
    {
        if (root == nullptr)
            return;
        help(root->left);
        v.push_back(root->val);
        help(root->right);
    }
};
