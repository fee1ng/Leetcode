//����Ҷ��֮����Ҫ�жϣ�
//1.�жϸýڵ��Ƿ�Ϊ��Ҷ�ӣ��������
//���ýڵ㲻Ϊ��Ҷ�ӣ�������ݹ���������
//2.ȥ��������������������Ҷ�ӣ�������Ҫ�ݹ�������

//�����������⣬����Ҫ�ж��Ƿ�Ϊ��Ҷ�ӣ��������


int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        if(root==NULL)
            return 0;
        if(root->left!=NULL)
        {
            if(root->left->left==NULL&&root->left->right==NULL)
                sum=sum+root->left->val;
            else
                sum=sum+sumOfLeftLeaves(root->left);
        }
        if(root->right!=NULL)
            sum+=sumOfLeftLeaves(root->right);
        return sum;
    }