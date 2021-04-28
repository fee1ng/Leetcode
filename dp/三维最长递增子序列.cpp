class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        sort(box.begin(), box.end());
        int n = box.size();
        vector<int> dp(n);
        for (int i = 0;i < n;i++)
        {
            dp[i] = box[i][2];

            for (int j = 0;j < i;j++)
            {
                if (box[i][0] > box[j][0] && box[i][1] > box[j][1] && box[i][2] > box[j][2])
                {
                    dp[i] = max(dp[i], dp[j] + box[i][2]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};