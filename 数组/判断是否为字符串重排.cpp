class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 == 0 || n2 == 0)
            return false;
        if (n1 != n2)
            return false;
        unordered_map<char, int> m1, m2;
        for (int i = 0, j = 0;i < n1, j < n2;i++, j++)
        {
            m1[s1[i]]++;
            m2[s2[j]]++;
        }
        for (int i = 0;i < n1;i++)
        {
            if (m1[s1[i]] != m2[s1[i]])
                return false;
        }
        return true;
    }
};



class Solution {
public:
    //ÅÅÐò
    bool CheckPermutation(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};