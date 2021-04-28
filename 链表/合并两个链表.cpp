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
    //preÖ¸ÕëºÍtailÖ¸Õë
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* p = list1;
        ListNode* pre = new ListNode;
        ListNode* tail = nullptr;
        int num = 0;
        while (p)
        {
            if (num == a - 1)
                pre = p;
            if (num == b + 1)
            {
                tail = p;
                break;
            }
            p = p->next;
            num++;
        }
        while (list2)
        {
            pre->next = list2;
            pre = pre->next;
            list2 = list2->next;
        }
        pre->next = tail;
        return list1;
    }
};