class Solution {
public:
    //������������ı���
    //����Ϊ�Ƿ�ѡ��ǰָ�������Ԫ��
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        dfs(nums, v, 0);
        res.push_back({});
        return res;
    }
    void dfs(vector<int>& nums, vector<int>& v, int i)
    {
        if (i == nums.size())
            return;
        //��ѡ��ǰԪ��
        dfs(nums, v, i + 1);
        //ѡ��ǰԪ��
        v.push_back(nums[i]);
        dfs(nums, v, i + 1);
        //��������
        res.push_back(v);
        //����
        v.pop_back();
    }
};



class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int>& nums)
    {
        int n = nums.size();
        //mask�Ķ�����λ��nλ����ǰmask�Ķ�����λjΪ1���������е�j��������������
        //2^n=mask��������Ϊ3��������8���Ӽ���ÿһ��mask����һ���Ӽ�״̬��mask�Ķ�������3λ
        for (int mask = 0; mask < (1 << n); ++mask)
        {
            t.clear();
            for (int i = 0; i < n; ++i)                 //���������ÿһλ
            {
                //���mask�Ķ�����ĳһλΪ1���������еĸ�λ��������
                if (mask & (1 << i))
                {
                    t.push_back(nums[i]);
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};