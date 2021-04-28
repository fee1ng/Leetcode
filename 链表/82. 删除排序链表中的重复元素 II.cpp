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
    //hash
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> m;
        ListNode* p=head;
        while(p)
        {
            m[p->val]++;
            p=p->next;
        }
        ListNode* curr=new ListNode;
        ListNode* first=curr;
        for(auto t:m)
        {
            if(t.second==1)
            {
                curr->next=new ListNode(t.first);
                curr=curr->next;
            }
        }
        return first->next;
    }
};


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
    //增加一个头节点first，令a=first,b=head
    //若a->next->val!=b->next->val，则都前进一位
    //反之，则移动b直到a->next->val!=b->next->val,并让a->next=b->next,b=b->next
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* first = new ListNode;
        first->next = head;
        ListNode* a = first;
        ListNode* b = head;
        while (b && b->next)
        {
            if (a->next->val != b->next->val)
            {
                a = a->next;
                b = b->next;
            }
            else
            {
                while (b != nullptr && b->next != nullptr && a->next->val == b->next->val)
                {
                    b = b->next;
                }
                a->next = b->next;
                b = b->next;
            }
        }
        return first->next;
    }
};