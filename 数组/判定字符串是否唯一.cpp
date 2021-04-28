class Solution {
public:
    bool isUnique(string astr) {
        int n = astr.size();
        if (n == 0)
            return true;
        unordered_map<char, int> v;
        for (int i = 0;i < n;i++)
        {
            char c = astr[i];
            v[c]++;
            if (v[c] > 1)
                return false;
        }
        return true;
    }
};