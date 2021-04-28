struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};
void Morris_inorder(TreeNode* root)
{
	TreeNode* cur = root;
	while (cur != nullptr)
	{
		if (cur->left != nullptr)
		{
			TreeNode* pre = cur->left;
			//�ҵ��������е�����Ҷ�ӽڵ�
			while (pre->right != nullptr && pre->right != cur)
			{
				pre = pre->right;

			}
			//�ҵ�������������Ҷ�ӽڵ�����pre->rightΪ�գ������ҽڵ���cur�ڵ����
			//��ʱΪ��һ�ε��������������Ҷ�
			if (pre->right == nullptr)
			{
				pre->right = cur;
				cur = cur->left;	//�Ƶ�cur�ڵ�
			}
			//��Ϊ����˵��pre->right=cur,��ʱҪ�����Զ������ָ�Ϊ�������ṹ
			//��ʱΪ�ڶ��ε��������������Ҷ�
			else
			{
				pre->right = nullptr;
				cout << cur->val << endl;
				cur = cur->right;
			}
		}
		//���������Ϊ�գ���������ڵ㼰��������
		else
		{
			cout << cur->val << endl;
			cur = cur->right;
		}
	}
}