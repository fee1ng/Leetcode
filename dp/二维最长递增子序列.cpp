class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //auto match=[] (vector<int>& v1,vector<int>& v2) {return v1[0]<v2[0];};
        int n = envelopes.size();
        if (n == 0)
            return 0;

        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 1;i < n;i++)
        {
            dp[i] = 1;
            for (int j = 0;j < i;j++)
            {
                if (envelopes[j][1] < envelopes[i][1] && envelopes[j][0] < envelopes[i][0])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};