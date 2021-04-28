class Solution {
public:
    //滑动窗口
    //只有need有的字符才加入windows中，否则会在match出错
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> windows;
        unordered_map<char,int> need;
        for(auto c:s1)
        {
            need[c]++;
        }
        int left=0,right=0;
        int size=s2.size();
        int match=0;
        while(right<size)
        {   
            char c1=s2[right];
            if(need.count(c1))
            {
                windows[c1]++;
                if(windows[c1]==need[c1])
                    match++;
            }
            right++;
            while(match==need.size())
            {   
               char c2=s2[left];
               if(right-left==s1.size())
                    return true;
                else
                {   
                    if(need.count(c2))
                    {
                        windows[c2]--;
                        if(windows[c2]<need[c2])
                            match--;
                    }
                    left++;
                }
            }
        }
        return false;
    }
};