//��ÿһ������������ԣ���������dfs�������
//������
 int res=0;
    int pathSum(TreeNode* root, int sum) {
        preorder(root,sum);
        return res;
    }
    void dfs(TreeNode* root,int sum)
    {   
        if(root==nullptr)
            return;
        if(root->val==sum)
            res++;
        dfs(root->left,sum-root->val);
        dfs(root->right,sum-root->val);
    }
    void preorder(TreeNode* root,int sum)
    {
        if(root==nullptr)
            return;
        dfs(root,sum);
        preorder(root->left,sum);
        preorder(root->right,sum);
    }

    //����ǰ׺��
    //����ڵ�A�ͽڵ�B��ǰ׺�����ֵΪtarget��˵���ڵ�A���ڵ�B·�����Ϊtarget
    //����Ŀ������sumΪtarget�����������ÿһ���ڵ��ǰ׺��currSum���Ǹýڵ�ΪB
    //��currSum-target����֤ǰ׺��ΪcurrSum-target�Ľڵ�A���������
    //����map<int,int>��¼ǰ׺��(key)�͸�ǰ׺�ͳ��ֵĴ���(value)
    //����ڵ�A��������У�A���ܲ�ֹ��һ��������res+��ǰ׺�ͳ��ֵĴ���
    int res = 0;
    //֤���ڵ�A�Ƿ�������
    void dfs(TreeNode* root, int currSum, int sum, map<int, int> mp)
    {
        if (root == nullptr)
            return;
        currSum += root->val;     //�õ�B�ڵ��ǰ׺��
        if (mp.find(currSum - sum) != mp.end())   //�����ǰǰ׺�ͼ�ȥҪ���·����֮���ǰ׺����map�У�˵���ڵ�A����������У�˵������n��·��
        {
            res += mp[currSum - sum];
        }
        mp[currSum]++;
        dfs(root->left, currSum, sum, mp);
        dfs(root->right, currSum, sum, mp);
        mp[currSum]--;      //������һ�㣬��ǰ׺�ͳ��ֵĴ���-1
    }
    int pathSum(TreeNode* root, int sum) {
        map<int, int> mp;
        mp[0] = 1;      //��ʼ��ǰ׺�ͣ�ǰ׺��Ϊ0���ִ���Ϊ1
        dfs(root, 0, sum, mp);
        return res;
    }