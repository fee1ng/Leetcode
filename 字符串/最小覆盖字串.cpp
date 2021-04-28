//给你一个字符串 S、一个字符串 T 。请你设计一种算法，可以在 O(n) 的时间复杂度内，从字符串 S 里面找出：包含 T 所有字符的最小子串。
class Solution {
public:
    //滑动窗口
    //先让right尽可能扩大，再缩小left与right的距离
    string minWindow(string s, string t) {
        //当window对应字符出现的次数大于need出现的次数，说明可以成功
        unordered_map<char, int> window;
        unordered_map<char, int> need;
        int match=0;    //当前已经符合条件的字符个数
        int minLen=INT_MAX;
        int left=0,right=0;
        int start=0;    //字串的起点
        //将目标字串字符的个数统计
        for(int i=0;i<t.size();i++)
        {
            need[t[i]]++;
        }
        while(right<s.size())
        {
            char tmp=s[right];
            if(need.count(tmp)) //如果该字符是要求的
            {
                window[tmp]++;
                if(window[tmp]==need[tmp])
                    match++;
            }
            right++;
            //求最小字串
            while(match==need.size())       //说明要求字串已经全部出现，逐步缩小结果字串的长度
            {
                //更新最小字串的位置与长度
                if(minLen>right-left)
                {
                    start=left;
                    minLen=right-left;
                }
                char c2=s[left];
                //防止缩过头
                if(need.count(c2))
                {
                    window[c2]--;
                    if(need[c2]>window[c2])
                        match--;
                }
                left++;
            }
        }
        return minLen == INT_MAX ?
                "" : s.substr(start, minLen);
    }
};