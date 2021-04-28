//�軷��ΪL,����ָ��������P��slowָ�����ڵ㵽������P�ľ���=b,P����ڵ����Ϊc,��b+c=L
//������ͷ������ڵ�ľ���Ϊa
/*
 ֱ������ʱ��fastָ���߹��ľ���Ϊ:
 L(fast)=a+n(b+c)+b=a+(n+1)b+nc
 slowָ���߹��ľ���Ϊ:
 L(slow)=a+b
 ��2L(slow)=L(fast),��2(a+b)=a+(n+1)b+nc   =>>  a=(n-1)L+c
 ������ͷ����ڵ�ľ���a=������P����ڵ�ľ���(n-1)L+c
 */
//��slow=head,fast=�����㣬����һ��ֱ����������Ϊ��ڵ�
//slow�뻷ʱ fastһ���ڻ��ڣ�fast��slow�������ٶȣ���slow����һ����ʱ��fast�϶�Ҳ���������������Աض�����slow����һ��ǰĳ����������
class Solution {
public:
    //����ָ���ҵ������ڵ����slow=head��fastΪ�����ڵ�
    //֮������ָ���ǰ��һ��ֱ���������õ�Ϊ������ڵ�
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