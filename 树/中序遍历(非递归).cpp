#include <iostream>
#include<vector>
//ģ���ֹ������ķ�ʽ������ջ�������һ��������Ϊ�յĽڵ㣬��������Ϊ��ʱ�򱣴沢���Ա�����������

vector<int> res;
stack<TreeNode*> s;
vector<int> inorderTraversal(TreeNode* root) {
    while (root || !s.empty())
    {
        if (root)
        {
            s.push(root);
            root = root->left;
        }
        else
        {
            TreeNode* curr = s.top();
            s.pop();
            res.push_back(curr->val);
            root = curr->right;
        }
    }
    return res;
}