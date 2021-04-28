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
        vector<int> left(n, 1);     //���㵱ǰλ�����λ�Ĺ�������ǰλ>���λ����ǰλ���ǹ�����ߵ��ǹ���1
        vector<int> right(n, 1);    //���㵱ǰλ���ұ�λ�Ĺ�������ǰλ>�ұ�λ����ǰλ���ǹ����ұ�λ���ǹ���1
        int res = 0;
        //��ǰλ��ǰһλ������Ҫ���ǹ�����ǰһλ��1
        for (int i = 0;i < n;i++)
        {
            if (i > 0 && ratings[i] > ratings[i - 1])
                left[i] = left[i - 1] + 1;
        }
        //��ǰλ�Ⱥ�һλ������Ҫ���ǹ����Ⱥ�һλ��1
        for (int i = n - 1;i >= 0;i--)
        {
            if (i<n - 1 && ratings[i]>ratings[i + 1])
                right[i] = right[i + 1] + 1;
            //ĳһλ��Ҫ���ǹ�=���㵱ǰλ����������������ֵ
            res += max(right[i], left[i]);
        }
        return res;
    }
};