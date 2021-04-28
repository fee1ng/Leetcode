class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        //begin��¼���俪ʼֵ
        //last��¼��ǰ��������ǰһλ
        //end��¼��ǰ������ֵ
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
            //���ظ�Ԫ��
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
        //���һ������
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