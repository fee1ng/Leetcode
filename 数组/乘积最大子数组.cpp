class Solution {
public:
    //动态规划
    //“由于存在负数，那么会导致最大的变最小的，最小的变最大的。因此还需要维护当前最小值imin
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> dpMax(n);
        vector<int> dpMin(n);
        dpMax[0] = nums[0], dpMin[0] = nums[0];
        int res = nums[0];
        for (int i = 1;i < n;i++)
        {
            dpMax[i] = max(dpMax[i - 1] * nums[i], max(nums[i], dpMin[i - 1] * nums[i]));
            dpMin[i] = min(dpMin[i - 1] * nums[i], min(nums[i], dpMax[i - 1] * nums[i]));
        }
        return *max_element(dpMax.begin(), dpMax.end());
    }
};