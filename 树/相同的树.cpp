//�ж�������ͬ����ֱ��ж�����������������
//��������ǰ�ڵ��ֵ��ͬ����ͬ������Ҫ�ж�
//��������ṹ��һ�����򷵻ز�ͬ
//������ʽ������������������
//�ݹ���ֹ����Ϊ��p,q�ڵ㶼Ϊ��ʱ
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