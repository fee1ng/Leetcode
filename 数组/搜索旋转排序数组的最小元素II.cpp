class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int left = 0, right = n - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else if (nums[mid] < nums[right])
                right = mid;
            //当nums[mid]==nums[right]，由于相同元素的存在，我们并不知道最小元素到底在mid的哪一边，但可以确定的是右边界有元素可以被替代，故不要右边界，即right--
            else
            {
                right--;
            }
        }
        return nums[left];
    }
};