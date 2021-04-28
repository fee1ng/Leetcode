//从每一个点出发都可以，考虑两个dfs先序遍历
//暴力法
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

    //利用前缀和
    //如果节点A和节点B的前缀和相差值为target，说明节点A到节点B路径求和为target
    //令题目给定的sum为target，计算遍历的每一个节点的前缀和currSum，记该节点为B
    //令currSum-target，求证前缀和为currSum-target的节点A在这颗树中
    //利用map<int,int>记录前缀和(key)和该前缀和出现的次数(value)
    //如果节点A在这颗树中，A可能不止有一个，所以res+该前缀和出现的次数
    int res = 0;
    //证明节点A是否在树中
    void dfs(TreeNode* root, int currSum, int sum, map<int, int> mp)
    {
        if (root == nullptr)
            return;
        currSum += root->val;     //得到B节点的前缀和
        if (mp.find(currSum - sum) != mp.end())   //如果当前前缀和减去要求的路径和之后的前缀和在map中，说明节点A存在这颗树中，说明存在n条路径
        {
            res += mp[currSum - sum];
        }
        mp[currSum]++;
        dfs(root->left, currSum, sum, mp);
        dfs(root->right, currSum, sum, mp);
        mp[currSum]--;      //返回上一层，该前缀和出现的次数-1
    }
    int pathSum(TreeNode* root, int sum) {
        map<int, int> mp;
        mp[0] = 1;      //初始化前缀和，前缀和为0出现次数为1
        dfs(root, 0, sum, mp);
        return res;
    }