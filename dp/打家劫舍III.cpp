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
    //��ǰ�ڵ�������״̬��һ��ѡ��ǰ�ڵ㣬һ�ֲ�ѡ��ǰ�ڵ㣬��������ϣ��key-value��Ӧ��ǰ�ڵ�ѡ��ֵ�Ͳ�ѡ��ֵ

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
        //ѡ��ǰ�ڵ㣬�����ӽڵ㲻��ѡ+root->val
        s[root] = ns[root->left] + ns[root->right] + root->val;
        //��ѡ��ǰ�ڵ㣬�������ӽڵ��ѡ�ɲ�ѡ��ȡ�����ӽڵ�����ֵ���
        ns[root] = max(s[root->left], ns[root->left]) + max(s[root->right], ns[root->right]);
        //�������ֵ
        res = max(res, max(s[root], ns[root]));
    }
};