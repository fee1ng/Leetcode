/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
//层序遍历
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root==nullptr)
            return nullptr;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                Node* curr=q.front();
                q.pop();
                if(curr==nullptr)
                    continue;
                if(size>=1)
                    curr->next=q.front();
                else
                    curr->next=nullptr;
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return root;
    }
};
// @lc code=end

