/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> hash;
        for(int i=0;i<n;i++)
        {
            if(hash.find(target-nums[i])!=hash.end())
            {
                return {i,hash[target-nums[i]]};
            }
            else
            {
                hash[nums[i]]=i;
            }
        }
        return {};
    }
};
// @lc code=end

