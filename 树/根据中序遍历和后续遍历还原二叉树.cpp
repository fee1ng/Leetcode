TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return help(inorder, 0, inorder.size(), postorder, 0, postorder.size());
}
//后序遍历：左子树，右子树，根节点
//中序遍历：左子树，根节点，右子树
//根据中序遍历情况二分数组递归建立左右子树
//找到左子树节点的个数，确定新的左右子树数组范围
//左闭右开去间
TreeNode* help(vector<int>& inorder, int i_left, int i_right, vector<int>& postorder, int p_left, int p_right)
{
    if (i_left >= i_right || p_left >= p_right)
        return NULL;
    int RootVal = postorder[p_right - 1];
    int pos = 0;
    for (int i = i_left;i < i_right;i++)
        if (inorder[i] == RootVal)
        {
            pos = i;
            break;
        }
    int NumOfLeft = pos - i_left;               //左子树节点的个数
    TreeNode* root = new TreeNode(RootVal);   //建立根节点
    root->left = help(inorder, i_left, pos, postorder, p_left, p_left + NumOfLeft);
    root->right = help(inorder, pos + 1, i_right, postorder, p_left + NumOfLeft, p_right - 1);
    return root;
}