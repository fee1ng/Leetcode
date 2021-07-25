/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        auto check = [&] (int h,int mid)
        {
            int count=0;
            for(int i=0;i<piles.size();i++)
            {
                if(piles[i]%mid==0)
                    count+=piles[i]/mid;
                else
                    count+=piles[i]/mid+1;
            }
            if(count>h)
                return false;
            return true;
        };
        while(left<right)
        {
            int mid=(left+right)/2;
            if(check(h,mid))
                right=mid;
            else
                left=mid+1;
        }
        return left;
    }
};
// @lc code=end

