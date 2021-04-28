/*�����������е������ڵ㱻����ؽ�����

���ڲ��ı���ṹ������£��ָ��������*/
//������������������õ�Ӧ�����������飬���������ҳ�a[i]>a[i+1]��������
//����ֵ�����в�����������λ�û�����������������һ����
//���������������������λ��i,j�����Ӧ�Ĵ���ڵ�Ϊa[i]��a[j+1]����¼����x,y
//���ֻ��һ��������������λ��i����Ϊa[i]��a[i+1]����¼x,y
//�ڶ������������ҵ�x,y������

vector<int> v;
void recoverTree(TreeNode* root) {
    if (root == nullptr)
        return;
    dfs(root);
    int x = -1, y = -1;
    for (int i = 0;i < v.size() - 1;i++)
    {
        if (v[i] > v[i + 1])
        {
            y = v[i + 1];
            if (x == -1)
                x = v[i];
            else
                break;
        }
    }
    //�ҵ������x,y
    //�ڶ����������н���x,y
    swap(root, x, y, 2);
}
void swap(TreeNode* root, int x, int y, int count)
{
    if (root == nullptr)
        return;
    if (root->val == x || root->val == y)
    {
        root->val = root->val == x ? y : x;     
        //if(--count==0)
            //return;
    }
    swap(root->left, x, y, count);
    swap(root->right, x, y, count);
}
//�������
void dfs(TreeNode* root)
{
    if (root == nullptr)
        return;
    dfs(root->left);
    v.push_back(root->val);
    dfs(root->right);
}