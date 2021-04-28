//���Ƿ���������������BΪ
//1.��A������������
//2.��A������������
//3.����AΪ���ڵ������
//���A��BΪ�գ��򷵻�false
//�������dfs�У���������Ϊ1.AΪ��B���ջ�A,B��ֵ���ȣ�����false
//2.A��Ϊ�գ�B�գ����ж�������ɣ�����true
//��һ���ж�A��B�������ӽڵ��Ƿ����
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