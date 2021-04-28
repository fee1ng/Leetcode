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
        //����ʱpreָ���������һ���ڵ㣬�γ�ѭ������
        pre->right = head;
        head->left = pre;
        return head;
    }
    //�������
    void dfs(Node* root)
    {
        if (root == nullptr)
            return;
        dfs(root->left);
        //preָ���Ѿ��γ���������һ���ڵ㣬���䲻Ϊ�գ��򽫵�ǰroot�ڵ��������
        if (pre != nullptr)
            pre->right = root;
        //preΪ�գ�˵������δ�γɣ�root�ڵ�Ϊ�����׽ڵ�
        else
            head = root;
        //�γ�˫������leftָ��ָ��ǰ��һ���ڵ�
        root->left = pre;
        //����pre�ڵ�
        pre = root;
        dfs(root->right);
    }
};