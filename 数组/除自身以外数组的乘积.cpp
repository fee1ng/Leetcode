class Solution {
public:
    //左乘积数组left，left[i]表示第i位元素左边所有元素的乘积
    //右乘积数组right,right[i]表示第i位元素右边所有元素的乘积
    //res[i]=left[i]*right[i]
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        vector<int> res(n);
        left[0] = 1;
        for (int i = 1;i < n;i++)
        {
            left[i] = left[i - 1] * nums[i - 1];
        }
        right[n - 1] = 1;
        for (int i = n - 2;i >= 0;i--)
        {
            right[i] = right[i + 1] * nums[i + 1];
        }
        for (int i = 0;i < n;i++)
        {
            res[i] = left[i] * right[i];
        }
        return res;
    }
};