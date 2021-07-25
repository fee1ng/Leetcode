
#include <vector>
#include <algorithm>
#include<numeric>
using namespace std;
//max<=t<=sum
//对给定的t，查看他是否满足m次分割的情况
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int max_ele=*max_element(nums.begin(),nums.end());
        int sum=accumulate(nums.begin(),nums.end(),0);
        int left=max_ele,right=sum;
        auto check = [=] (int m,int mid)
        {
            int sum=0;
            m--;
            for(int i=0;i<nums.size();i++)
            {   
                if(m<0)
                    return false;
                if(sum+nums[i]<=mid)
                    sum+=nums[i];
                else
                {
                    sum=nums[i];
                    m--;
                }
            }
            if(m<0)
                return false;
            return true;
        };
        
        while(left<right)
        {
            int mid=(left+right)/2;
            if(check(m,mid))
                right=mid;
            else
                left=mid+1;
        }
        return left;
    }
};
// @lc code=end

