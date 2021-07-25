/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132 模式
 */

// @lc code=start
#include <vector>
#include <stack>
#include <set>
using namespace std;
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return false;
        //s为单调递减栈，记录可能的3值
        stack<int> s;
        //mid记录2的最大值
        int mid=INT_MIN;
        s.push(nums[n-1]);
        for(int i=n-2;i>=0;i--)
        {   
            //nums[i]<mid，则找到了1
            if(nums[i]<mid)
                return true;
            //把当前不可能当3的元素弹出
            while(!s.empty()&&nums[i]>s.top())
            {
                mid=s.top();
                s.pop();
            }
            //3入栈
            if(nums[i]>mid)
                s.push(nums[i]);
        }
        return false;
    }
};
// @lc code=end

