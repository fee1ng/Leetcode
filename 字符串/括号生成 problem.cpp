class Solution {
public:
    //暴力在每个位置遍历所有可能，判断是否合法
    bool jundge(string s)
    {
        int balance=0;
        for(char c:s)
        {
            if(c=='(')
                balance++;
            else if(c==')')
                balance--;
            if(balance<0)
                return false;
        }
        if(balance!=0)
            return false;
        else
            return true;
    }
    //在当前位置考虑加上'('或者')'
    void help(string curr,int n,vector<string>& res)
    {
        if(n==curr.size())
        {   
            if(jundge(curr))
                res.push_back(curr);
            return;
        }
        curr=curr+'(';
        help(curr,n,res);
        curr.pop_back();
        curr=curr+')';
        help(curr,n,res);
        curr.pop_back();
            
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;
        help(curr,n*2,res);
        return res;
    }
};




class Solution {
public:
    //回溯 一边生成一边检验
    void help(string curr,int n,vector<string>& res,int balance)
    {   
        if(balance<0)
            return;
        if(n==curr.size())
        {
             if(balance==0)
                res.push_back(curr);
            return;
        }   
        curr+='(';
        balance++;
        help(curr,n,res,balance);
        curr.pop_back();
        balance--;
        curr+=')';
        balance--;
        help(curr,n,res,balance);
        curr.pop_back();
        balance++;
    }
    vector<string> generateParenthesis(int n) {
        string curr;
        vector<string> res;
        int balance=0;
        help(curr,n*2,res,balance);
        return res;
    }
};

class Solution {
public:
    //回溯 尽可能地生成正确地答案
    void help(string curr,int n,vector<string>& res,int L,int R)
    {   
        
        if(n==curr.size())
        { 
             res.push_back(curr);
            return;
        }   
        if(L<n/2)       //左括号在长度不大于n地情况下可无限生成
        {
            curr+='(';
            help(curr,n,res,L+1,R);
            curr.pop_back();
        }
        if(R<L)         //当右括号长度小于左括号时，应及时生成右括号
        {
            curr+=')';
            help(curr,n,res,L,R+1);
            curr.pop_back();
        }  
    }
    vector<string> generateParenthesis(int n) {
        string curr;
        vector<string> res;
        int balance=0;
        help(curr,n*2,res,0,0);
        return res;
    }
};