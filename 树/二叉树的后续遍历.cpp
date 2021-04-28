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
    //˳��Ϊ�������������������ڵ�
    //�ؼ������жϵ�ǰ���ڵ��Ƿ������������������Ƿ��Ѿ�������
    //��û����������������δ��������ֱ�ӽ����ڵ��ֵ���飬���������������轫���ڵ��ٴ���ջ�ұ���������
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* pre = nullptr;
        while (root != nullptr || !s.empty())
        {
            //��������ջ
            while (root)
            {
                s.push(root);
                root = root->left;
            }
            //��ֵrootΪջ������Ϊ��ǰ���ڵ�
            root = s.top();
            s.pop();

            //root->right==nullptr˵����ǰ�ڵ�û��������
            //root->right==pre˵���������Ѿ�������
            //������������������ڵ��ֵ
            if (root->right == nullptr || root->right == pre)
            {
                res.push_back(root->val);
                pre = root;
                root = nullptr;
            }
            //����˵����δ�����������������ڵ��ٴ���ջ�����л���ǰ�ڵ�Ϊ������
            else
            {
                s.push(root);
                root = root->right;
            }
        }
        return res;
    }
};