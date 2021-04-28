/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //顺序为左子树，右子树，根节点
    //关键在于判断当前根节点是否有右子树且右子树是否已经遍历过
    //若没有右子树或右子树未遍历，则直接将根节点的值入组，若有右子树，则需将根节点再次入栈且遍历右子树
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* pre = nullptr;
        while (root != nullptr || !s.empty())
        {
            //左子树入栈
            while (root)
            {
                s.push(root);
                root = root->left;
            }
            //赋值root为栈顶，即为当前根节点
            root = s.top();
            s.pop();

            //root->right==nullptr说明当前节点没有右子树
            //root->right==pre说明右子树已经遍历完
            //以上两种情况则加入根节点的值
            if (root->right == nullptr || root->right == pre)
            {
                res.push_back(root->val);
                pre = root;
                root = nullptr;
            }
            //否则，说明有未遍历的右子树，根节点再次入栈，且切换当前节点为右子树
            else
            {
                s.push(root);
                root = root->right;
            }
        }
        return res;
    }
};