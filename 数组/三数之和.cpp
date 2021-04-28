class Solution {
public:
    //给定确定的a,b，有且仅有一个c满足a+b+c=0
    //对数组进行排序，在第二层循环时令c从数组右端递减，直到b+c<-a，才让b增加看是否能令a+b+c=0
    //总体思路：排序+双指针，注意去重，这次枚举的数和上次不同
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n < 3)
            return res;
        sort(nums.begin(), nums.end());
        for (int i = 0;i < n;i++)
        {
            int k = n - 1;
            //去重，这次枚举的数和上次不同
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1;j < n;j++)
            {   
                //去重
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                //由于b在逐渐增大，则令a+b+c=0的c必定越来越小
                /*
                如果我们固定了前两重循环枚举到的元素 a和 b，那么只有唯一的 c 满足 a+b+c=0.当第二重循环往后枚举一个元素 b'则有b'>b满足a+b+c=0
                的c' 一定在c的左侧，所以可以从大到小枚举c，从小到大枚举b
                */
                while (j < k && nums[i] + nums[j] + nums[k]>0)
                    k--;
                if (nums[i] + nums[j] + nums[k] > 0)
                    break;
                if (j == k)
                    break;
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> v = { nums[i],nums[j],nums[k] };
                    res.push_back(v);
                }
            }
        }
        return res;
    }
};