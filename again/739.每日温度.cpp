/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    //下一个更大的数字
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int> s;
        vector<int> res(n);
        for(int i=0;i<n;i++)
        {
            {
                while(!s.empty()&&temperatures[i]>temperatures[s.top()])
                {
                    res[s.top()]=i-s.top();
                    s.pop();
                }
                
            }
            s.push(i);
            
        }
         while(!s.empty())
        {
            res[s.top()]=0;
            s.pop();
        }
        return res;
    }
};
// @lc code=end

