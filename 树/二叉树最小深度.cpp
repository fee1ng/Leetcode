 int minDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        //������Ҷ�ӽڵ�ʱ����ʼ�߶�Ϊ1
        if(root->left==NULL&&root->right==NULL)
            return 1;
        //�������������������ĸ߶�
        int l=minDepth(root->left);
        int r=minDepth(root->right);
        //������������������һ��Ϊ����һ����Ϊ�գ��򷵻ز�Ϊ���Ǹ��ĸ߶�+1
        if(root->left==NULL||root->right==NULL)
            return max(l,r)+1;
        //��ʱ������������������Ϊ�գ����ظ߶Ƚ�С��+1
        return min(l,r)+1;
    }