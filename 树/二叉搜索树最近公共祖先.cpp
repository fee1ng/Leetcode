TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //fei di gui
        if(root==nullptr)
            return nullptr;
        if(p==root||q==root)
            return root;
        while(root!=nullptr)
        {
            if(root->val>max(p->val,q->val))
                root=root->left;
            else if(root->val<min(p->val,q->val))
                root=root->right;
            else   
                return root;
        }
        return root;
    }