class Solution {
public:
    //���򣬷��������
    //1.���nums[i+1]==nums[i]+1,��ǰ��������������ȡ��ʷ����������Ⱥ͵�ǰ�������Ƚϴ���Ϊ���
    //2.���nums[i+1]==nums[i],����
    //���򣬵�ǰ��������=1
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 0)
            return 0;
        int res = 1;
        int curr = 1;
        for (int i = 0;i < n - 1;i++)
            if (nums[i + 1] == nums[i] + 1)
            {
                curr++;
                res = max(curr, res);
            }
            else if (nums[i + 1] == nums[i])
                continue;
            else
                curr = 1;
        return res;
    }
};



class Solution {
public:
    //hash map,����nums[i]+1�Ƿ��ڹ�ϣ����
    //ͬʱ����nums[i]-1Ҳ�ڹ�ϣ���У������жϣ���Ϊ��nus[i]���ɵ���������Ϊnums[i]-1�������е��ִ�
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for (auto& n : nums)
            hash.insert(n);
        int res = 0;
        for (auto& i : nums)
        {
            if (!hash.count(i) - 1)
            {
                int curr = 1;
                int currentNum = i;
                while (hash.count(currentNum + 1))
                {
                    curr++;
                    currentNum++;
                }
                res = max(res, curr);
            }
        }
        return res;
    }
};