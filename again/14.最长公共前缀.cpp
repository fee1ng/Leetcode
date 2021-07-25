/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0)
            return "";
        string res;
        int size=strs[0].size();
        int flag=0;
        for(int i=0;i<size;i++)
        {
            char c=strs[0][i];
            for(int j=1;j<n;j++)
            {
                if(i<strs[j].size())
                {
                    if(strs[j][i]!=c)
                    {
                        flag=1;
                        break;
                    }
                }
                else
                {
                    flag=1;
                    break;
                }
            }
            if(!flag)
                res+=c;
            else
                break;
        }
        return res;
    }
};
// @lc code=end

