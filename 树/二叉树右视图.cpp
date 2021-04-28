vector<int> rightSideView(TreeNode* root) {
    return level(root);
}
//层序遍历当前层，找最后一个元素
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