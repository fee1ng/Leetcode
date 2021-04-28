/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//set����
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
    // ���������ȷֱ�ΪL1+C��L2+C�� CΪ�������ֵĳ���.
    //��һ��������L1+C���󣬻ص��ڶ����������L2��.
    //��2��������L2+C���󣬻ص���һ���������L1��.���������ߵĲ�����ΪL1+L2+Cʱ�ͱ��ཻ
    //������L1+L2+2C��ʱ�������ڵ��=һ���ڵ㣬��Ӧ�������ཻ���
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

//�㳤�ȷ�
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