/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }
        stack<int> s;
        //单调不增序列
        vector<int> res(n*2);
        for(int i=0;i<n*2;i++)
        {
            if(s.empty()||nums[i]<=nums[s.top()])
                s.push(i);
            else
            {
                while(!s.empty()&&nums[s.top()]<nums[i])
                {
                    res[s.top()]=nums[i];
                    s.pop();
                }
                s.push(i);
            }
        }
        while(!s.empty())
        {
            res[s.top()]=-1;
            s.pop();
        }
        res.resize(n);
        return res;
    }
};
// @lc code=end

