class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> nums(n, 1);


        for(int i=0;i<n;i++)
        {
            for (int j = i;j >= 1;j--)
            {
                if (ratings[j] < ratings[j - 1])
                {

                     nums[j-1] = max(nums[j]+1, nums[j-1]);
                }
                else
                    break;
            }
            for(int j=i+1;j<n;j++)
            {
                if(ratings[j]>ratings[j-1])
                {
                    nums[j]=max(nums[j],nums[j-1]+1);
                }
                else
                    break;
            }
        }
        int res=0;
        for(int i=0;i<nums.size();i++)
            res+=nums[i];
        return res;
    }
};


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1);     //满足当前位与左边位的规则，若当前位>左边位，则当前位的糖果比左边的糖果多1
        vector<int> right(n, 1);    //满足当前位与右边位的规则，若当前位>右边位，则当前位的糖果比右边位的糖果多1
        int res = 0;
        //当前位比前一位大，则需要的糖果数比前一位多1
        for (int i = 0;i < n;i++)
        {
            if (i > 0 && ratings[i] > ratings[i - 1])
                left[i] = left[i - 1] + 1;
        }
        //当前位比后一位大，则需要的糖果数比后一位多1
        for (int i = n - 1;i >= 0;i--)
        {
            if (i<n - 1 && ratings[i]>ratings[i + 1])
                right[i] = right[i + 1] + 1;
            //某一位需要的糖果=满足当前位左右两个规则的最大值
            res += max(right[i], left[i]);
        }
        return res;
    }
};