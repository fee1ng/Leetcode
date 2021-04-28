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

//�ݹ�
class Solution {
public:
    //���������Ѿ���k�ڵ㣬��k+1-kn�ڵ��Ѿ���ת����Ҫ��תk�ڵ��k+1�ڵ�,currָ���k���ڵ�
    //��curr->next->next=curr
    //curr->next=nullptr
    //newHeadʼ��ָ��ת���ͷ��ͨ���������д��뽫ͷ��Ľڵ�������(����)
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};