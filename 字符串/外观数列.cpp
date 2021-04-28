class Solution {
public:
    string countAndSay(int n) {
        //第n层依赖于n-1的输出，考虑递归的结束条件为n=1
        //根据前面的结果完善结果res字符串
        if(n==1)
            return "1";
        string pre=countAndSay(n-1);
        string res;
        int count=1;
        for(int i=0;i<pre.size();i++)
        {
            if(pre[i]==pre[i+1])
            {
                count++;
            }
            else
            {
                res+=to_string(count)+pre[i];
                count=1;
            }
        }
        return res;
    }
};