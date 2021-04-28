//先序遍历：根节点，左子树集合，右子树集合
//中序遍历：左子树集合，根节点，右子树集合
//找到根节点，再根据小集合递归构建二叉树
//二分大数组
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return help(preorder, 0, preorder.size(), inorder, 0, inorder.size());
}
TreeNode* help(vector<int>& preorder, int p_left, int p_right, vector<int>& inorder, int i_left, int i_right)
{
    if (p_left >= p_right || i_left >= i_right)
        return nullptr;
    int val = preorder[p_left];     //当前根节点的值
    TreeNode* root = new TreeNode(val);
    int tmp = 0;
    for (int i = i_left;i < i_right;i++)
        if (inorder[i] == val)
            tmp = i;      //找到根节点在中序遍历数组中的位置
    //二分中序遍历数组建立二叉树
    //在前序遍历数组中确定范围
    int leftNum = tmp - i_left;     //左子树的节点总数
    root->left = help(preorder, p_left + 1, p_left + leftNum + 1, inorder, i_left, tmp);
    //左子树集合下标范围为(p_left+1)------>(p_left+左子树的个数+1) (左区间为闭区间，右区间为开区间)
    root->right = help(preorder, p_left + leftNum + 1, p_right, inorder, tmp + 1, i_right);
    //同理如上
    return root;
}