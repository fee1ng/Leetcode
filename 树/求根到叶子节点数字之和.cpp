//Ҫ��ͣ���Ǯ�õ�ÿһ����Ҷ�ӽڵ����������Ҫ�ж�Ҷ�ӽڵ�
//�ó����ĵ��ƹ�ʽs=s*10+root->val
//����ǰ�����
vector<int> v;
    int sumNumbers(TreeNode* root) {
        currSum(root,0);
        int sum=0;
        for(int i=0;i<v.size();i++)
            sum+=v[i];
        return sum;
    }
    void currSum(TreeNode* root,int s)
    {   
        if(root!=nullptr)
        {
            s=s*10+root->val;
            if(root->left==nullptr&&root->right==nullptr)
                v.push_back(s);
            currSum(root->left,s);
            currSum(root->right,s);
        }
    }



    int sumNumbers(TreeNode* root)
    {
        return currSum(root, 0);
    }
    int currSum(TreeNode* root, int s)
    {
        if (root == nullptr)
            return 0;
        s = s * 10 + root->val;     //��ǰ��
        if (root->left == nullptr && root->right == nullptr)
            return s;               //����һ����ǰ����Ҷ�ӽڵ����
        return currSum(root->left, s) + currSum(root->right, s);    //������������������������ӽ��
    }