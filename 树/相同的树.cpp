//判断两树相同，则分别判断其左子树和右子树
//若两树当前节点的值不同，则不同，所以要判断
//如果两树结构不一样，则返回不同
//遍历方式考虑深度优先中序遍历
//递归终止条件为当p,q节点都为空时
bool res = true;
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == q)
        return true;
    dfs(p, q);
    return res;
}
void dfs(TreeNode* p, TreeNode* q)
{
    if (p == nullptr && q == nullptr)
        return;
    if ((p == nullptr && q) || (p && q == nullptr))
    {
        res = false;
        return;
    }
    dfs(p->left, q->left);
    if (p->val != q->val)
    {
        res = false;
        return;
    }
    dfs(p->right, q->right);
} bool res=true;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==q)
            return true;
         dfs(p,q);
         return res;
    }
    void dfs(TreeNode* p,TreeNode* q)
    {
        if(p==nullptr&&q==nullptr)
            return;
        if((p==nullptr&&q)||(p&&q==nullptr))
        {
             res=false;
             return;
        }  
        dfs(p->left,q->left);
        if(p->val!=q->val)
        {
             res=false;
             return;
        }  
        dfs(p->right,q->right);
    }