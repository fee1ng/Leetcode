/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* pre, * head;
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr)
            return root;
        dfs(root);
        //结束时pre指向链表最后一个节点，形成循环链表
        pre->right = head;
        head->left = pre;
        return head;
    }
    //中序遍历
    void dfs(Node* root)
    {
        if (root == nullptr)
            return;
        dfs(root->left);
        //pre指向已经形成链表的最后一个节点，若其不为空，则将当前root节点加入链表
        if (pre != nullptr)
            pre->right = root;
        //pre为空，说明链表未形成，root节点为链表首节点
        else
            head = root;
        //形成双向链表，left指针指向前面一个节点
        root->left = pre;
        //更新pre节点
        pre = root;
        dfs(root->right);
    }
};