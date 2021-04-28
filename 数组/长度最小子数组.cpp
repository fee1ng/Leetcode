class Solution {
public:
    //滑动窗口
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int left = 0, right = 0;
        queue<int> q;       //先进先出
        int sum = 0;
        int res = INT_MAX;
        while (right < n)
        {
            sum += nums[right];
            q.push(nums[right]);
            while (sum > s)
            {
                int tmp = right - left + 1;
                if (tmp < res)
                    res = tmp;
                int curr = q.front();
                q.pop();
                sum -= curr;
                left++;
            }
            if (sum == s)
            {
                int tmp = right - left + 1;
                if (tmp < res)
                    res = tmp;
            }
            right++;
        }
        if (res == INT_MAX)
            return 0;
        return res;
    }
};