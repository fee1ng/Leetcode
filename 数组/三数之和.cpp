class Solution {
public:
    //����ȷ����a,b�����ҽ���һ��c����a+b+c=0
    //��������������ڵڶ���ѭ��ʱ��c�������Ҷ˵ݼ���ֱ��b+c<-a������b���ӿ��Ƿ�����a+b+c=0
    //����˼·������+˫ָ�룬ע��ȥ�أ����ö�ٵ������ϴβ�ͬ
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n < 3)
            return res;
        sort(nums.begin(), nums.end());
        for (int i = 0;i < n;i++)
        {
            int k = n - 1;
            //ȥ�أ����ö�ٵ������ϴβ�ͬ
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1;j < n;j++)
            {   
                //ȥ��
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                //����b������������a+b+c=0��c�ض�Խ��ԽС
                /*
                ������ǹ̶���ǰ����ѭ��ö�ٵ���Ԫ�� a�� b����ôֻ��Ψһ�� c ���� a+b+c=0.���ڶ���ѭ������ö��һ��Ԫ�� b'����b'>b����a+b+c=0
                ��c' һ����c����࣬���Կ��ԴӴ�Сö��c����С����ö��b
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