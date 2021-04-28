class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //hash table
        unordered_map<int, int> table;
        int n = nums.size();
        vector<int> res;
        for (int i = 0;i < n;i++)
        {
            table[nums[i]]++;
        }
        for (auto it : table)
        {
            if (it.second > n / 3)
                res.push_back(it.first);
        }
        return res;
    }
};

//�㷨˼��������������ѡ���Լ��������������������ͺ�ѡ����ͬʱ���Ӧ������+1�������������ѡ�˶�����ͬ��������������-1����һ��������Ϊ0ʱ��������Ӧ�ĺ�ѡ�ˡ�
//������ʣ�µ�����2��������
//�������ǿ��Էֳ��������� ����һ������������������
//������˼��һ��������ʱ������������ѡ�˶���һ����ֵ������һ�λ�ƴ
//1.����һ���������������� ����ƴ��������1��
//2.ĳ��������2�������� ����ƴ��ĳ��������1������������2.
class Solution {
public:
    //�����׶Σ�������ͬͶƱ���жԿӣ�����ͬʱ��������һ��Ʊ���������ͶƱ��ͬ�����ۼӿɵ����Ĵ�����
    //�����׶Σ��ڵ����׶����õ��ĵ�������ֻҪ��Ϊ 0���������ѡ�����п��ܳ���һ���Ʊ���ģ�Ϊ����֤������Ҫ����һ�Σ�ͳ��Ʊ�����ſ�ȷ����
    //�������ѡһ������������Ʊ������Ҫ����һ�루1/2����Ʊ����
    //�������ѡ�������������ǵ�Ʊ������Ҫ����(1/3)��Ʊ����
    //�������ѡm�����������ǵ�Ʊ������Ҫ���� [ 1 / (m + 1) ] ��Ʊ����
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int v1 = nums[0];
        int v2 = nums[0];
        int count1 = 0, count2 = 0;
        //ͶƱ�׶Σ���ǰԪ��ƥ��������������ͬ��Ʊ�����ӣ���ͬ�����
        //����������Ʊ��Ϊ0ʱ����������µ���
        for (int curr : nums)
        {
            if (curr == v1)
            {
                count1++;
                continue;
            }
            if (curr == v2)
            {
                count2++;
                continue;
            }
            if (count1 == 0)
            {
                v1 = curr;
                count1++;
                continue;
            }
            if (count2 == 0)
            {
                v2 = curr;
                count2++;
                continue;
            }
            count1--;
            count2--;
        }

        //ͳ�ƽ׶�
        count1 = 0, count2 = 0;
        for (int curr : nums)
        {
            if (curr == v1)
                count1++;
            else if (curr == v2)
                count2++;
        }
        if (count1 > n / 3)
            res.push_back(v1);
        if (count2 > n / 3)
            res.push_back(v2);
        return res;
    }
};