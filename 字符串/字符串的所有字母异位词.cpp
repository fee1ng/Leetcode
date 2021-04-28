class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        int match = 0;
        vector<int> res;
        int left = 0, right = 0;
        for (char c : p)
        {
            need[c]++;
        }
        while (right < s.size())
        {
            char c1 = s[right];
            //如果该字符为目标字符
            if (need.count(c1))
            {
                window[c1]++;
                if (window[c1] == need[c1])
                {
                    match++;
                }
            }
            right++;
            while (match == need.size())
            {
                if (right - left == p.size())
                {
                    res.push_back(left);
                }
                char c2 = s[left];
                if (need.count(c2))
                {
                    window[c2]--;
                    if (window[c2] < need[c2])
                        match--;
                }
                left++;
            }
        }
        return res;
    }
};