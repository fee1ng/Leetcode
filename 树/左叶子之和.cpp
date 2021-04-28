//求左叶子之和需要判断：
//1.判断该节点是否为左叶子，是则求和
//若该节点不为左叶子，则继续递归其左子树
//2.去右子树中找左子树的左叶子，所以需要递归右子树

//遍历方法随意，但需要判断是否为左叶子，是则求和


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