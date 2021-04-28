class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        //begin记录区间开始值
        //last记录当前遍历到的前一位
        //end记录当前遍历的值
        vector<string> res;
        int n = nums.size();
        if (n == 0)
            return res;
        long begin = nums[0];
        long last = nums[0];
        long end;
        for (int i = 1;i < n;i++)
        {
            end = nums[i];
            //无重复元素
            if (end - last > 1)
            {
                if (begin == last)
                {
                    string curr = to_string(begin);
                    res.push_back(curr);
                }
                else
                {
                    string curr = to_string(begin) + "->" + to_string(last);
                    res.push_back(curr);
                }
                begin = end;
                last = end;
                continue;

            }
            else
            {
                last = end;
            }
        }
        //最后一个区间
        if (begin == last)
        {
            string curr = to_string(begin);
            res.push_back(curr);
        }
        else
        {
            string curr = to_string(begin) + "->" + to_string(last);
            res.push_back(curr);
        }
        return res;
    }
};