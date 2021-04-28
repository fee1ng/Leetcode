//遍历左右子树，找到p,q节点
//如果p,q在左子树找不到，则 p和 q一定都在右子树中，右子树中先遍历到的那个就是最近公共祖先
//如果p,q在右子树找不到，则...................
//如果p,q分别在左右子树，返回当前节点
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)
            return nullptr;
        if(root==q||root==p)    //自己是自己的祖先
            return root;
        //在左子树中找p,q节点
        TreeNode * left=lowestCommonAncestor(root->left,p,q);
        //在右子树找p,q节点
        TreeNode *right=lowestCommonAncestor(root->right,p,q);
        //在左子树和右子树都找到了，祖先为root
        if(left!=nullptr&&right!=nullptr)
            return root;
        //左子树找到了右子树没有，则左子树节点为祖先
        if(left!=nullptr&&right==nullptr)
            return left;
        //右子树找到了左子树没有，则右子树节点为祖先
        if(right!=nullptr&&left==nullptr)
            return right;
        return nullptr;
    }