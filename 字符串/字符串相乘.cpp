class Solution {
public:
    //num1的第i位(高位从0开始)和num2的第j位相乘的结果在乘积中的位置是[i+j, i+j+1]
    string multiply(string num1, string num2) {
        int n1=num1.size()-1;
        int n2=num2.size()-1;
        if(n1<0||n2<0)
            return "";
        vector<int> v(n1+n2+2,0);
        for(int i=n1;i>=0;i--)
            for(int j=n2;j>=0;j--)
            {
                int tmpmul=(num1[i]-'0')*(num2[j]-'0'); 
                tmpmul+=v[i+j+1];       //加上低位看是否有进位
                v[i+j]+=tmpmul/10;
                v[i+j+1]=tmpmul%10;
            }
        int i=0;
        string res;
        while(i<v.size()-1&&v[i]==0)    //去除前面多余的0
            i++;
        for(;i<v.size();i++)
            res+=to_string(v[i]);
        return res;
    }
};