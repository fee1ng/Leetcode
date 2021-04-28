//判是否是子树，考虑树B为
//1.树A左子树的子树
//2.树A右子树的子树
//3.以树A为根节点的子树
//如果A或B为空，则返回false
//先序遍历dfs中，结束条件为1.A为空B不空或A,B的值不等，返回false
//2.A不为空，B空，则判断子树完成，返回true
//进一步判断A和B的左右子节点是否相等
bool isSubStructure(TreeNode* A, TreeNode* B) {
    if (A == nullptr || B == nullptr)
        return false;
    return isSubStructure(A->left, B) || isSubStructure(A->right, B) || dfs(A, B);
}
bool dfs(TreeNode* A, TreeNode* B)
{
    if (A == nullptr && B != nullptr)
        return false;
    if (B == nullptr)
        return true;
    if (A->val != B->val)
        return false;
    return dfs(A->left, B->left) && dfs(A->right, B->right);
}