//暴力解法
class Solution {
public:
    string longestPalindrome(string s) {
        //对每一个长度超过2的字符串进行检查
        if(s.size()==0)
            return "";
        if(s.size()==1)
            return s;
        string res;
        int max=0;
        for(int i=0;i<s.size();i++) //左边界
        {    
            char c=s[i];
            string tmp;     //保存当前字串
            tmp=tmp+c;
            for(int j=i+1;j<s.size();j++)
            {
                tmp+=s[j];
                if(help(tmp))       //当前字串是否为回文串
                {
                    if(tmp.size()>max)
                    {
                        max=tmp.size();
                        res=tmp;
                    }
                }

            }
        }
        if(res.size()==0)       //如果没找到最长回文字串，长度为2的字串中任意字母都为其最长回文子串
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

//动态规划，先得出小字串的结果，再得出大字串的结果
//先对长度为1的字串统一得出结果，再对长度为2的........
//长度为1的字串与长度为2的字串为特例
class Solution {
public:
    string longestPalindrome(string s) {
        //动态规划
        //先判断字符串中较小字串是否回文
        string res;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));  //维护左边界i到右边界j是否为回文串
        int i, j;
        for (int L = 0;L < n;L++)    //当前判断字串的长度-1   一开始L=0即字串长度为1
        {
            for (int i = 0;i + L < n;i++)          //左边界,结束条件为右边界越界
            {
                int j = i + L;          //左边界加上字串长度-1即为右边界
                if (L == 0)            //长度为1的字串都为回文串
                    dp[i][j] = 1;
                else if (L == 1)
                    dp[i][j] = (s[i] == s[j]);        //长度为2的字串为回文串需要两个字母相等
                else
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];    //大回文串中有小回文串，所以判断大回文串只须判断两边和中间字串是否为回文串
                if (dp[i][j] && L + 1 > res.size())            //当前区域字串为回文串且当前判断字串的长度大于当前结果字串的长度，更新结果字串
                    res = s.substr(i, L + 1);
            }
        }
        return res;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        //中心扩散
        //遍历所有长度为1与长度为2的字串，进行中心扩散，找到最长回文字串
        //最小的回文子串为长度为1或2的字串
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
        while (left >= 0 && right < s.size() && (s[left] == s[right]))     //从中间往左右扩散
        {
            left--;
            right++;
        }
        return { left + 1,right - 1 };
    }
};