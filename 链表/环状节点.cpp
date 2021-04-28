//设环长为L,快慢指针相遇点P，slow指针从入口点到相遇点P的距离=b,P到入口点距离为c,有b+c=L
//设链表开头到环入口点的距离为a
/*
 直到相遇时，fast指针走过的距离为:
 L(fast)=a+n(b+c)+b=a+(n+1)b+nc
 slow指针走过的距离为:
 L(slow)=a+b
 由2L(slow)=L(fast),有2(a+b)=a+(n+1)b+nc   =>>  a=(n-1)L+c
 即链表头到入口点的距离a=相遇点P到入口点的距离(n-1)L+c
 */
//令slow=head,fast=相遇点，各走一步直到相遇，则为入口点
//slow入环时 fast一定在环内；fast是slow的两倍速度，当slow走完一环的时候fast肯定也走完了两环，所以必定会在slow走完一环前某个点相遇。
class Solution {
public:
    //快慢指针找到相遇节点后，令slow=head，fast为相遇节点
    //之后两个指针各前进一步直到相遇，该点为环的入口点
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head, * slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                slow = head;
                while (fast && slow)
                {
                    if (fast == slow)
                        return fast;
                    fast = fast->next;
                    slow = slow->next;
                }
            }
        }
        return nullptr;
    }
};



class Solution {
public:
    //hash
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> s;
        ListNode* p = head;
        while (p)
        {
            if (s.count(p))
                return p;
            s.insert(p);
            p = p->next;
        }
        return nullptr;
    }
};