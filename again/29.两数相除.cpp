/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int _dividend, int _divisor) {
        int flag=0;
        //int sign=0;
        long dividend=_dividend;
        long divisor=_divisor;
        if(divisor<0&&dividend>0)
        {
            flag=1;
            divisor=-divisor;
        }
        else if(divisor<0&&dividend<0)
        {
            divisor=-divisor;
            dividend=-dividend;
        }
        else if(dividend<0&&divisor>0)
        {
            dividend=-dividend;
            flag=1;
        }
        int res=0;
        while(dividend>=divisor)
        {
            dividend-=divisor;
            res++;
        }
        if(flag)
            res=-res;
        return res;
    }
};
// @lc code=end

