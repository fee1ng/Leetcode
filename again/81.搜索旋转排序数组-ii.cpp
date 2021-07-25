/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
#include <vector>
using namespace std;
//处理重复数字
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0,right=n-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]==target)
                return true;
            else if(nums[mid]>nums[left])
            {
                if(nums[mid]>target&&nums[left]<=target)
                    right=mid-1;
                else
                    left=mid+1;
            }
            else if(nums[mid]<nums[left])
            {
                if(nums[mid]<target&&nums[n-1]>=target)
                    left=mid+1;
                else
                    right=mid-1;
            }
            else
                left++;
        }
        return false;
    }
};
// @lc code=end

