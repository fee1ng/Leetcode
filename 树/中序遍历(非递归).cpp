#include <iostream>
#include<vector>
//模仿手工遍历的方式，利用栈保存最后一个左子树为空的节点，当左子树为空时则保存并尝试遍历其右子树

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