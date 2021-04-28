
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        vector<int> v;
        int count=0;
        ListNode* first=new ListNode;
        first->next=head;
        ListNode* p=first;
        ListNode* tmp=new ListNode;
        ListNode* last=nullptr;
        while(p)
        {   
            if(count>=m&&count<=n)
            {   
               
                v.push_back(p->val);
                count++;
                p=p->next;
            }
            else if(count==m-1)
            {
                tmp=p;
                p=p->next;
                count++;
            }
            else if(count==n+1)
            {
                last=p;

                break;
            }
            else
            {
                p=p->next;
                count++;
            }
        }
        for(int i=v.size()-1;i>=0;i--)
        {
            tmp->next=new ListNode(v[i]);
            tmp=tmp->next;
        }
        tmp->next=last;
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
    //pre,tmp,curr完成交换
    //con指向m-1个节点，tail指向第m个节点
    //循环结束后，con->next=pre,此时curr=n+1个节点
    //tail->next=curr，吃此时tail为第n个节点
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* first = new ListNode(-1);
        first->next = head;
        ListNode* pre = nullptr;
        ListNode* curr = first;
        ListNode* tmp = nullptr;
        ListNode* con = nullptr;
        ListNode* tail = nullptr;
        int count = 0;
        while (curr)
        {
            if (count == m - 1)
            {
                con = curr;
                tail = curr->next;
                count++;
                curr = curr->next;
            }
            else if (count >= m && count <= n)
            {
                tmp = curr->next;
                curr->next = pre;
                pre = curr;
                curr = tmp;
                count++;
            }
            else if (count > n)
            {
                tail->next = curr;
                con->next = pre;
                break;
            }
            else
            {
                count++;
                curr = curr->next;
            }
        }
        tail->next = curr;
        con->next = pre;
        return first->next;
    }
};