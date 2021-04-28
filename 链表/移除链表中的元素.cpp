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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr = head;
        ListNode* first = new ListNode(-1);
        first->next = head;
        ListNode* pre = first;
        while (curr)
        {
            if (curr->val == val)
            {
                pre->next = curr->next;
                //delete curr;
                curr = curr->next;
            }
            else
            {
                curr = curr->next;
                pre = pre->next;
            }
        }
        return first->next;
    }
};