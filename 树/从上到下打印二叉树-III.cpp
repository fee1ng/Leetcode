/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //֮���δ�ӡ������������������ż����������
    //������������Ҵ�ӡ��ż������������ӡ������Ҫһ��ջ�洢ÿһ��Ľڵ�
    //������������������ջ�����ջʱ�������ȳ�ջ������ż���������������ȴ�ӡ����֮ͬ��
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        stack<TreeNode*> q;
        if (root == nullptr)
            return res;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            int size = q.size();
            level++;
            vector<int> v;
            vector<TreeNode*> node;
            while (size--)
            {
                TreeNode* curr = q.top();
                q.pop();
                //ż�����Ƚ�������
                if (level % 2 == 0)
                {
                    v.push_back(curr->val);
                    if (curr->right != nullptr)
                        //q.push(curr->right);
                        node.push_back(curr->right);
                    if (curr->left != nullptr)
                        //q.push(curr->left);
                        node.push_back(curr->left);
                }
                //���������Ƚ�������
                else
                {
                    v.push_back(curr->val);
                    if (curr->left != nullptr)
                        //q.push(curr->left);
                        node.push_back(curr->left);
                    if (curr->right != nullptr)
                        //q.push(curr->right);
                        node.push_back(curr->right);
                }
            }
            if (v.size() != 0)
                res.push_back(v);
            //ͳһ��ջ��һ��ڵ�
            for (auto n : node)
                q.push(n);
        }
        return res;
    }
};