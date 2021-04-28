class Solution {
public:
    //key-value
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();
        if (n == 0)
            return -1;
        int i;
        for (i = 0;i < n;i++)
        {
            m[nums[i]]++;
            if (m[nums[i]] > 1)
                break;
        }
        return nums[i];
    }
};


class Solution {
public:
    //����Ϊn�����飬���ַ�Χ��0-n-1,��˵����û�ظ����ź��������Ӧ��nums[i]=i
    //ɨ�������е�ÿ�����֣���ɨ�赽���±�Ϊi,��nums[i]=m
    //���ȱȽ�m��i�Ƿ���ȣ������ɨ����һλ����
    //���������nums[m]�Ƚϣ�������򷵻أ�������򽻻���ֵ,�����Ƚ�
    //ʹ��һ�α�����ԭ����������ظ����֣���ô��һ�ΰ�nums[m]��nums[i]�����󣬻���nums[i]=i��
    //��ô�ڶ����ҵ�����ظ�����ʱ������m==nums[m]
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return -1;
        for (int i = 0;i < n;i++)
        {
            int m = nums[i];
            if (m == i)
                continue;
            else
            {
                if (m == nums[m])
                    return m;
                else
                    swap(nums[m], nums[i]);
            }
        }
        return -1;
    }
    void swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
};


class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        //����nums[i]=i��һһ��Ӧ
        for (int i = 0;i < n;i++)
        {
            while (nums[i] != i)
            {
                if (nums[i] == nums[nums[i]])
                    return nums[i];
                int temp = nums[i];   //i=1,temp=3
                nums[i] = nums[temp]; //����nums[temp]
                nums[temp] = temp;    //����nums[3]=3
            }
        }
        return -1;
    }
};