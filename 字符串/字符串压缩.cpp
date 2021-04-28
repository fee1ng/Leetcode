class Solution {
public:
    string compressString(string S) {
        //Ë«Ö¸Õë½ØÁô
        int n = S.size();
        if (n == 0)
            return S;
        string res;
        int count = 1;
        int i = 0, j = 1;
        while (j < n)
        {
            if (S[i] == S[j])
            {
                count++;
                j++;
            }
            else
            {
                res.push_back(S[i]);
                res += to_string(count);
                i = j;
                j = j + 1;
                count = 1;
            }
        }
        if (i == n - 1)
        {
            res.push_back(S[i]);
            res.push_back('1');
        }
        else
        {
            res.push_back(S[i]);
            res += to_string(count);
        }
        if (res.size() < n)
            return res;
        else
            return S;
    }
};