class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //以第一个字符串为标准遍历其每个字符
        //将遍历到的每个字符与后面的字符串比较
        //退出条件：当有字符串完全被遍历完时或有不同时
        //因为最大公共前缀肯定出现在最短的字符串中
        int j=0;
        string res;
        if(strs.size()==0)
            return res;
        int i;
        for(auto ch:strs[0])
        {
            for(i=1;i<strs.size();i++)
            {
                if(j<strs[i].size())
                {   
                    if(strs[i][j]!=ch)
                        return res;
                }
                else
                    return res;
            }
            res+=strs[i-1][j];
            j++;
        }
        return res;
    }
};
string longestCommonPrefix(vector<string>& strs) {
    //两个两个比较
    //拿当前的公共字串进行后续比较（递归）
    if (strs.size() == 0)
        return "";
    string longstr = strs[0];
    for (int i = 1;i < strs.size();i++)
    {
        longstr = help(longstr, strs[i]);
        if (longstr.size() == 0)       //当前最长公共字串为空，没有比较意义
            break;
    }
    return longstr;
}
string help(string s1, string s2)
{
    int index = 0;
    int L = min(s1.size(), s2.size());
    while (s1[index] == s2[index] && index < L)
        index++;
    return s1.substr(0, index);
}