/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>
#include <unordered_set>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        unordered_set<char> window;
        int left=0,right=0;
        int n=s.size();
        while(right<n)
        {   
            char c=s[right];
            if(window.find(c)==window.end())
            {
                window.insert(c);
            }
            else
            {
                while(s[left]!=c)
                {
                    window.erase(s[left]);
                    left++;
                }
                window.erase(s[left]);
                left++;
                window.insert(c);
            }
            right++;
            res=max(res,right-left);
        }
        return res;
    }
};
// @lc code=end

