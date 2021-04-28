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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* curr = new ListNode;
        ListNode* first = curr;
        while (p && q)
        {
            if (p->val <= q->val)
            {
                curr->next = new ListNode(p->val);
                curr = curr->next;

                p = p->next;
            }
            else
            {
                curr->next = new ListNode(q->val);
                curr = curr->next;
                q = q->next;
            }
        }
        while (p)
        {
            curr->next = new ListNode(p->val);
            curr = curr->next;
            p = p->next;
        }
        while (q)
        {
            curr->next = new ListNode(q->val);
            curr = curr->next;
            q = q->next;
        }
        return first->next;
    }
};