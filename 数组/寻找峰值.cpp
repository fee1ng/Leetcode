class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        if (n == 2)
        {
            if (nums[0] > nums[1])
                return 0;
            else
                return 1;
        }
        for (int i = 1;i < n;i++)
        {
            if (i < n - 1)
            {
                if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                    return i;
            }
            else
            {
                if (nums[i] > nums[i - 1])
                    return i;
            }
        }
        return 0;
    }
};


class Solution {
public:
    //二分查找
    //若该元素恰好位于升序序列或者一个局部上升坡度中(nums[i]<nums[i+1]))，则说明峰值会在本元素的右边。
    //若该元素恰好位于降序序列或者一个局部下降坡度中(nums[i]>nums[i+1])，则说明峰值在本元素左边。
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid + 1])   //峰值在本元素(包括本元素左边)
                right = mid;
            else                        //峰值肯定在本元素右边且肯定不是本元素
                left = mid + 1;
        }
        return left;
    }
};