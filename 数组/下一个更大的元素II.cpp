class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //naive,��������2��������β��������������[1,2,3]->[1,2,3,1,2,3] O(n^2)
        int n = nums.size();
        nums.resize(2 * n);
        int j = 0;
        for (int i = n;i < 2 * n;i++, j++)
            nums[i] = nums[j];
        vector<int> res(n);
        for (int i = 0;i < n;i++)
        {
            int flag = 0;
            for (int j = i + 1;j < 2 * n;j++)
            {
                if (nums[i] < nums[j])
                {
                    res[i] = nums[j];
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                res[i] = -1;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //�����ݼ�ջ��ʹ��վ�ﶼ�ǵݼ�Ԫ�ص��±�
        int n = nums.size();
        nums.resize(2 * n);
        int j = 0;
        for (int i = n;i < 2 * n;i++, j++)
            nums[i] = nums[j];
        vector<int> res(n, -1);
        stack<int> minstk;
        int i = 0;
        while (i < 2 * n)
        {   
            //ջ��ֵ���ڵ��ڵ�ǰֵ��˵����ǰֵ������һ������Ԫ�أ���ջ��i++
            if (minstk.empty() || nums[minstk.top()] >= nums[i])
                minstk.push(i++);
            //��ǰֵ��ջ��һ����Ԫ�ص���һ������Ԫ�أ������res���飬��ջ����i����������Ϊ��ǰֵ������ջ��һ����Ԫ�ص���һ������Ԫ��
            else
            {   
                //ע�������ֹԽ��
                res[minstk.top() % n] = nums[i];
                minstk.pop();
            }
        }

        return res;
    }
};