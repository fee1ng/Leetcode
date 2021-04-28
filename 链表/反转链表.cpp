/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        vector<int> v;
        while (p && p->next)
        {
            v.push_back(p->val);
            p = p->next;
        }
        ListNode* first = p;
        for (int i = v.size() - 1;i >= 0;i--)
        {
            p->next = new ListNode(v[i]);
            p = p->next;
        }
        return first;
    }
};



class Solution {
public:
    //die dai
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        ListNode* next = nullptr;
        while (p)
        {
            ListNode* tmp = p->next;
            p->next = next;
            next = p;
            p = tmp;
        }
        return next;
    }
};

//递归
class Solution {
public:
    //假设现在已经在k节点，且k+1-kn节点已经反转，需要反转k节点和k+1节点,curr指向第k个节点
    //则curr->next->next=curr
    //curr->next=nullptr
    //newHead始终指向反转后的头，通过上面两行代码将头后的节点逐渐连接(增加)
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};