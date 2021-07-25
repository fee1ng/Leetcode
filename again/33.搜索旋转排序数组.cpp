/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start

#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0,right=n-1;
        while (left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
            {
                if(nums[mid]>=nums[n-1])
                    left=mid+1;
                else 
                {
                    if(nums[mid]<nums[n-1]&&nums[n-1]<target)
                        right=mid-1;
                    else 
                        left=mid+1;
                }
                    
            }
            //nums[mid]>target
            else
            {
                if(nums[mid]>=nums[n-1]&&nums[n-1]>=target)
                    left=mid+1;
                
                else 
                    right=mid-1;
            }
        }
        return -1;
        
    }
};
// @lc code=end

