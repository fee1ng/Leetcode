class Solution {
public:
    //¹þÏ£±í
    char firstUniqChar(string s) {
        unordered_map<char, int> m;
        if (s.size() == 0)
            return ' ';
        for (auto c : s)
        {
            m[c]++;
        }
        for (auto c : s)
        {
            if (m[c] == 1)
                return c;
        }
        return ' ';
    }
};