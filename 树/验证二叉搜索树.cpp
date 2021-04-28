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
    //��֮ǰ�Ľڵ���ȣ����С�ڵ��ڷ��ش���
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
//��ס��ǰ���������ֵ����Сֵ�����Ƚ�
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

//��������֤������������������
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
