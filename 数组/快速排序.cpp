class Solution {
public:
    //˫���ƶ�,��������
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
    void quicksort(vector<int>& v, int L, int R)
    {
        if (L < R)
        {
            int mid = help(v, L, R);
            quicksort(v, L, mid - 1);
            quicksort(v, mid + 1, R);
        }
    }
    int help(vector<int>& nums, int L, int R)
    {
        int i = L + 1, j = R;
        int key = nums[L];
        while (1)
        {
            while (i <= j && nums[i] <= key)
                i++;
            while (i <= j && nums[j] >= key)
                j--;
            if (i > j)
                break;
            swap(nums[i], nums[j]);
        }
        //��ʱ��j��λ�ü�Ϊkey��λ��
        swap(nums[j], nums[L]);
        return j;
    }
};


    class Solution {
    public:
        vector<int> sortArray(vector<int>& nums) {
            quicksort(nums, 0, nums.size() - 1);
            return nums;
        }
        void quicksort(vector<int>& nums, int L, int R)
        {
            if (L < R)
            {
                int mid = help(nums, L, R);
                quicksort(nums, L, mid - 1);
                quicksort(nums, mid + 1, R);
            }
        }
        int help(vector<int>& nums, int L, int R)
        {
            int key = nums[R];
            int i = L, j = L;    //iָ��λ�û�����һ��С��key��nums[j]����
            //jָ��ǰ�������������С��key�򽻻�
            //����ʱi��λ�þ���key��λ�ã�i��߶�ΪС��key��,�ұ߶�����key
            for (;j < R;j++)
            {
                if (nums[j] < key)
                {
                    swap(nums[i], nums[j]);
                    i++;
                }
            }
            nums[R] = nums[i];    //ԭ����iλ���ŵ����
            nums[i] = key;        //��key����ȥ��λ��
            return i;
        }
    };