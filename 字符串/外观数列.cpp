class Solution {
public:
    string countAndSay(int n) {
        //��n��������n-1����������ǵݹ�Ľ�������Ϊn=1
        //����ǰ��Ľ�����ƽ��res�ַ���
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