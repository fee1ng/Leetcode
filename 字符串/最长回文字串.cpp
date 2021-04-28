//�����ⷨ
class Solution {
public:
    string longestPalindrome(string s) {
        //��ÿһ�����ȳ���2���ַ������м��
        if(s.size()==0)
            return "";
        if(s.size()==1)
            return s;
        string res;
        int max=0;
        for(int i=0;i<s.size();i++) //��߽�
        {    
            char c=s[i];
            string tmp;     //���浱ǰ�ִ�
            tmp=tmp+c;
            for(int j=i+1;j<s.size();j++)
            {
                tmp+=s[j];
                if(help(tmp))       //��ǰ�ִ��Ƿ�Ϊ���Ĵ�
                {
                    if(tmp.size()>max)
                    {
                        max=tmp.size();
                        res=tmp;
                    }
                }

            }
        }
        if(res.size()==0)       //���û�ҵ�������ִ�������Ϊ2���ִ���������ĸ��Ϊ��������Ӵ�
            res=s[0];
        return res;    
    }
    bool help(string s)
    {   
        int size=s.size();
        int mid=size/2;
        if(size%2==0)
        {
            
            for(int i=mid-1,j=mid;i>=0&&j<size;i--,j++)
            {
                if(s[i]!=s[j])
                    return false;
            }
            return true;
        }
        else
        {
            for(int i=mid-1,j=mid+1;i>=0&&j<size;i--,j++)
            {
                if(s[i]!=s[j])
                    return false;
            }
            return true;
        }
    }
};

//��̬�滮���ȵó�С�ִ��Ľ�����ٵó����ִ��Ľ��
//�ȶԳ���Ϊ1���ִ�ͳһ�ó�������ٶԳ���Ϊ2��........
//����Ϊ1���ִ��볤��Ϊ2���ִ�Ϊ����
class Solution {
public:
    string longestPalindrome(string s) {
        //��̬�滮
        //���ж��ַ����н�С�ִ��Ƿ����
        string res;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));  //ά����߽�i���ұ߽�j�Ƿ�Ϊ���Ĵ�
        int i, j;
        for (int L = 0;L < n;L++)    //��ǰ�ж��ִ��ĳ���-1   һ��ʼL=0���ִ�����Ϊ1
        {
            for (int i = 0;i + L < n;i++)          //��߽�,��������Ϊ�ұ߽�Խ��
            {
                int j = i + L;          //��߽�����ִ�����-1��Ϊ�ұ߽�
                if (L == 0)            //����Ϊ1���ִ���Ϊ���Ĵ�
                    dp[i][j] = 1;
                else if (L == 1)
                    dp[i][j] = (s[i] == s[j]);        //����Ϊ2���ִ�Ϊ���Ĵ���Ҫ������ĸ���
                else
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];    //����Ĵ�����С���Ĵ��������жϴ���Ĵ�ֻ���ж����ߺ��м��ִ��Ƿ�Ϊ���Ĵ�
                if (dp[i][j] && L + 1 > res.size())            //��ǰ�����ִ�Ϊ���Ĵ��ҵ�ǰ�ж��ִ��ĳ��ȴ��ڵ�ǰ����ִ��ĳ��ȣ����½���ִ�
                    res = s.substr(i, L + 1);
            }
        }
        return res;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        //������ɢ
        //�������г���Ϊ1�볤��Ϊ2���ִ�������������ɢ���ҵ�������ִ�
        //��С�Ļ����Ӵ�Ϊ����Ϊ1��2���ִ�
        int n = s.size();
        int L = 0;
        int R = 0;
        for (int i = 0;i < n;i++)
        {
            auto [left1, right1] = help(s, i, i);
            auto [left2, right2] = help(s, i, i + 1);
            if (right1 - left1 > R - L)
            {
                L = left1;
                R = right1;
            }
            if (right2 - left2 > R - L)
            {
                L = left2;
                R = right2;
            }
        }
        return s.substr(L, R - L + 1);
    }
    pair<int, int> help(string s, int left, int right)
    {
        while (left >= 0 && right < s.size() && (s[left] == s[right]))     //���м���������ɢ
        {
            left--;
            right++;
        }
        return { left + 1,right - 1 };
    }
};