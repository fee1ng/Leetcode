class Solution {
public:
    //hash
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int> m;
        for (int i = 0;i < size;i++)
        {
            m[nums[i]]++;
            if (m[nums[i]] > size / 2)
                return nums[i];
        }
        return 0;
    }
};

class Solution {
public:
    //Ħ��ͶƱ,��ΪҪ�ҵ����ֳ��ִ������������ֳ��ֵĴ������࣬������Ϊ���vote>0������Ǹ���
    //�����ǰһλ��res��ͬ����vote++
    //�����ǰһλ��res��ͬ����vote--
    //���vote==0����res=nums[i]
    int majorityElement(vector<int>& nums) {
        int res = 0, MoleVote = 0;
        int n = nums.size();
        for (int i = 0;i < n;i++)
        {
            if (MoleVote == 0)
                res = nums[i];
            if (nums[i] != res)
                MoleVote--;
            else
                MoleVote++;
        }
        return res;
    }
};

//����ʱ������
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //���һ�����ֳ���һ�룬���ź����������������м�(n/2)
        //�ο���������ÿһ�ν�һ�����ַŵ����ʵĵط���ʹ����<key<��
        int n = nums.size();
        if (n == 1 || n == 2)
            return nums[0];
        int mid = n / 2;
        int start = 0, end = n - 1;
        int index = help(nums, 0, n - 1);
        while (index != mid)
        {
            if (index > mid)
            {
                end = index - 1;
                index = help(nums, start, end);
            }
            else
            {
                start = index + 1;
                index = help(nums, start, end);
            }
        }
        int res = nums[mid];
        return res;
    }
    int help(vector<int>& nums, int left, int right)
    {
        int key = nums[left];
        int i = left + 1, j = right;
        while (i <= j)
        {
            while (i <= j && nums[i] <= key)
                i++;
            while (i <= j && nums[j] >= key)
                j--;
            if (i > j)
                break;
            swap(nums[i], nums[j]);
        }
        nums[left] = nums[j];
        nums[j] = key;
        return j;
    }
};