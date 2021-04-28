//要求和，收钱得到每一个到叶子节点的数，所以要判断叶子节点
//得出数的递推公式s=s*10+root->val
//考虑前序遍历
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
        s = s * 10 + root->val;     //当前和
        if (root->left == nullptr && root->right == nullptr)
            return s;               //返回一个当前根到叶子节点的数
        return currSum(root->left, s) + currSum(root->right, s);    //继续遍历左子树右子树并相加结果
    }