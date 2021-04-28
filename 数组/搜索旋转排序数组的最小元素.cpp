class Solution {
public:
    //找到第一个逆序数字
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        for (int i = 0;i < n - 1;i++)
        {
            if (nums[i] > nums[i + 1])
            {
                res = nums[i + 1];
                break;
            }
        }
        return res;
    }
};


class Solution {
public:
    //给定数组只能是两个局部上升区间和一下全局上升区间
    //比较nums[mid]和最后一位元素
    //若nums[mid]>nums[right]，说明mid在第一个局部上升区间，但最小元素必定在第二个局部上升区间，所left=mid+1
    //否则，说明mid在第二个局部上升区间且在最小元素的右边或就为最小元素，所以让right=mid，缩小右半部范围
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            //若nums[mid]>nums[right]，说明最小元素在mid的右半边
            if (nums[mid] >= nums[n - 1])
            {
                left = mid + 1;
            }
            //否则则在左边
            else
                right = mid;
        }
        return nums[left];
    }
};