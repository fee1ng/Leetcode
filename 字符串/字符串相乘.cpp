class Solution {
public:
    //num1�ĵ�iλ(��λ��0��ʼ)��num2�ĵ�jλ��˵Ľ���ڳ˻��е�λ����[i+j, i+j+1]
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
                tmpmul+=v[i+j+1];       //���ϵ�λ���Ƿ��н�λ
                v[i+j]+=tmpmul/10;
                v[i+j+1]=tmpmul%10;
            }
        int i=0;
        string res;
        while(i<v.size()-1&&v[i]==0)    //ȥ��ǰ������0
            i++;
        for(;i<v.size();i++)
            res+=to_string(v[i]);
        return res;
    }
};