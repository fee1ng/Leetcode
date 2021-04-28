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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* first=new ListNode;
        first->next=head;
        ListNode* q=head,*p=first;
        while(q&&q->next)
        {
            if(p->next->val!=q->next->val)
            {
                p=p->next;
                q=q->next;
            }
            else
            {
                while(q&&q->next&&q->next->val==p->next->val)
                {
                    q=q->next;
                }
                p->next->next=q->next;
                p=p->next;
            }
        }
        return first->next;
    }
};