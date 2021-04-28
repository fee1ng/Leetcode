vector<int> rightSideView(TreeNode* root) {
    return level(root);
}
//���������ǰ�㣬�����һ��Ԫ��
vector<int> level(TreeNode* root)
{
    vector<int> res;
    queue<TreeNode*> q;
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
            if (size == 0)
                res.push_back(curr->val);
            if (curr->left != nullptr)
                q.push(curr->left);
            if (curr->right != nullptr)
                q.push(curr->right);
        }
    }
    return res;
}