class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> window;     //滑动窗口
        int maxLen=0;
        int left=0,right=0;
        while(right<s.size())
        {
            char c1=s[right];
            window[c1]++;
            right++;
            while(window[c1]>1)         //有重复字符，窗口开始缩减
            {
                char c2=s[left];
                window[c2]--;
                left++;
            }
            maxLen=max(maxLen,right-left);  //更新最长字串的长度
        }
        return maxLen;
    }
};