//���������������ҵ�p,q�ڵ�
//���p,q���������Ҳ������� p�� qһ�������������У����������ȱ��������Ǹ����������������
//���p,q���������Ҳ�������...................
//���p,q�ֱ����������������ص�ǰ�ڵ�
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)
            return nullptr;
        if(root==q||root==p)    //�Լ����Լ�������
            return root;
        //������������p,q�ڵ�
        TreeNode * left=lowestCommonAncestor(root->left,p,q);
        //����������p,q�ڵ�
        TreeNode *right=lowestCommonAncestor(root->right,p,q);
        //�������������������ҵ��ˣ�����Ϊroot
        if(left!=nullptr&&right!=nullptr)
            return root;
        //�������ҵ���������û�У����������ڵ�Ϊ����
        if(left!=nullptr&&right==nullptr)
            return left;
        //�������ҵ���������û�У����������ڵ�Ϊ����
        if(right!=nullptr&&left==nullptr)
            return right;
        return nullptr;
    }