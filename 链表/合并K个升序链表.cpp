/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//两个两个合并
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        ListNode* first = nullptr;
        for (int i = 0;i < lists.size();i++)
        {
            first = help(first, lists[i]);
        }
        return first;
    }
    //合并两个链表
    ListNode* help(ListNode* a, ListNode* b)
    {
        if (a == nullptr)
            return b;
        if (b == nullptr)
            return a;
        ListNode* p = a, * q = b;
        ListNode* head = new ListNode;
        ListNode* curr = head;
        while (p && q)
        {
            if (p->val < q->val)
            {
                curr->next = p;
                p = p->next;
            }
            else
            {
                curr->next = q;
                q = q->next;
            }
            curr = curr->next;
        }
        while (p)
        {
            curr->next = p;
            p = p->next;
            curr = curr->next;
        }
        while (q)
        {
            curr->next = q;
            q = q->next;
            curr = curr->next;
        }
        return head->next;
    }
};