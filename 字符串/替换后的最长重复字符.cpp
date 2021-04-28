class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int res = 0;
        int tmp = k;
        for (int i = 0;i < 26;i++)
        {
            queue<int> q;
            int len = 0;
            int left = 0, right = 0;
            char tar = 'A' + i;
            k = tmp;
            if (k == 0)
            {
                while (right < n)
                {
                    if (s[right] == tar)
                        len++;
                    else
                    {
                        left = right;
                        len = 0;
                    }
                    right++;
                    res = max(res, len);
                }
                continue;
            }
            while (right < n)
            {
                if (s[right] != tar)
                {
                    if (k > 0)
                    {
                        k--;
                        q.push(right);
                    }
                    else
                    {
                        if (!q.empty())
                        {
                            left = q.front() + 1;
                            q.pop();
                            q.push(right);
                        }
                    }
                }
                right++;
                len = max(len, right - left);

            }
            res = max(res, len);
        }
        return res;
    }
};