TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return help(inorder, 0, inorder.size(), postorder, 0, postorder.size());
}
//����������������������������ڵ�
//��������������������ڵ㣬������
//����������������������ݹ齨����������
//�ҵ��������ڵ�ĸ�����ȷ���µ������������鷶Χ
//����ҿ�ȥ��
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
    int NumOfLeft = pos - i_left;               //�������ڵ�ĸ���
    TreeNode* root = new TreeNode(RootVal);   //�������ڵ�
    root->left = help(inorder, i_left, pos, postorder, p_left, p_left + NumOfLeft);
    root->right = help(inorder, pos + 1, i_right, postorder, p_left + NumOfLeft, p_right - 1);
    return root;
}