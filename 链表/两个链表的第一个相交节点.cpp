/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//set容器
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        set<ListNode*> s;
        while (headA)
        {
            s.insert(headA);
            headA = headA->next;
        }
        while (headB)
        {
            if (s.find(headB) != s.end())
                return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};

class Solution {
public:
    // 两个链表长度分别为L1+C、L2+C， C为公共部分的长度.
    //第一个人走了L1+C步后，回到第二个人起点走L2步.
    //第2个人走了L2+C步后，回到第一个人起点走L1步.当两个人走的步数都为L1+L2+C时就必相交
    //在走完L1+L2+2C步时，两个节点必=一个节点，对应两链表不相交情况
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* p = headA, * q = headB;
        while (p != q)
        {
            if (p != nullptr)
                p = p->next;
            else
                p = headB;
            if (q != nullptr)
                q = q->next;
            else
                q = headA;
        }
        return p;
    }
};

//算长度法
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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode* p = headA, * q = headB;
        int countA = 1;
        int countB = 1;
        while (p && p->next)
        {
            countA++;
            p = p->next;
        }
        while (q && q->next)
        {
            countB++;
            q = q->next;
        }
        if (p->val != q->val)
            return nullptr;
        int m = 0;
        if (countA < countB)
        {
            while (m < countB - countA)
            {
                headB = headB->next;
                m++;
            }
        }
        else
        {
            while (m < countA - countB)
            {
                headA = headA->next;
                m++;
            }
        }
        while (headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};