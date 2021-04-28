//������������ڵ㣬���������ϣ�����������
//������������������ϣ����ڵ㣬����������
//�ҵ����ڵ㣬�ٸ���С���ϵݹ鹹��������
//���ִ�����
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return help(preorder, 0, preorder.size(), inorder, 0, inorder.size());
}
TreeNode* help(vector<int>& preorder, int p_left, int p_right, vector<int>& inorder, int i_left, int i_right)
{
    if (p_left >= p_right || i_left >= i_right)
        return nullptr;
    int val = preorder[p_left];     //��ǰ���ڵ��ֵ
    TreeNode* root = new TreeNode(val);
    int tmp = 0;
    for (int i = i_left;i < i_right;i++)
        if (inorder[i] == val)
            tmp = i;      //�ҵ����ڵ���������������е�λ��
    //��������������齨��������
    //��ǰ�����������ȷ����Χ
    int leftNum = tmp - i_left;     //�������Ľڵ�����
    root->left = help(preorder, p_left + 1, p_left + leftNum + 1, inorder, i_left, tmp);
    //�����������±귶ΧΪ(p_left+1)------>(p_left+�������ĸ���+1) (������Ϊ�����䣬������Ϊ������)
    root->right = help(preorder, p_left + leftNum + 1, p_right, inorder, tmp + 1, i_right);
    //ͬ������
    return root;
}