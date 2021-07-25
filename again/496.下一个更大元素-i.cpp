/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution {
public:
    //单调不增栈
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int,int> m;
        for(int i=0;i<nums2.size();i++)
        {
            if(s.empty()||nums2[i]<=nums2[s.top()])
                s.push(i);
            else
            {   
                while(!s.empty()&&nums2[s.top()]<nums2[i])
                {
                    m[nums2[s.top()]]=nums2[i];
                    s.pop();
                }
                s.push(i);
            }
        }
        while(!s.empty())
        {
            m[nums2[s.top()]]=-1;
            s.pop();
        }
        vector<int> res;
        for(auto i:nums1)
        {
            res.push_back(m[i]);
        }
        return res;
    }
};
// @lc code=end

