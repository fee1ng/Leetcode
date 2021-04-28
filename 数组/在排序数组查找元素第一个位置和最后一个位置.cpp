class Solution {
public:
    //���ַ�(�������������Ӹ�)
    //���nums[mid]<target,��target���Ұ�����
    //���nums[mid]>target����target���������
    //�����ȣ�����midΪ��㣬����������target����㣬��������target���յ�
    //���ж��ֵ�������left<right��������ѭ��
    //���left==right����Ҫ�����ж�������Ƿ����target�������ڣ�������յ㶼��ȣ��������ֻ����һ��
    //��Ϊ�ߵ�left==rightʱ˵��֮ǰ��û�ҵ�target��˵����ʹ����ҵ�target��Ҳֻ�����һ��
    //��size==0��size==1�������ж�
    //дwhile(left<right)ʱ���˳�ʱΪleft==right����Ȼ��ʣ��һ������Ҫ�����жϣ�����д�����Կ��Ǳ߽缰��ѭ�����ⷵ�ش�
    //��дwhile(left<=right),�˳�ʱΪleft=right+1�������������ѭ�����ߺ��Ա߽磬��һ��Ҫ��ѭ�����ﷵ�ش𰸡�
    vector<int> res = { -1,-1 };
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0)
            return { -1,-1 };
        if (size == 1)
        {
            if (nums[0] == target)
                return { 0,0 };
            else
                return { -1,-1 };
        }
        help(nums, target, 0, size - 1);
        return res;
    }
    void help(vector<int>& nums, int target, int left, int right)
    {

        if (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < target)
                help(nums, target, mid + 1, right);
            else if (nums[mid] > target)
                help(nums, target, left, mid);
            else
            {
                int tmp = mid;
                while (mid >= left && nums[mid] == target)
                    mid--;
                res[0] = mid + 1;
                mid = tmp;
                while (mid <= right && nums[mid] == target)
                {
                    mid++;
                }
                res[1] = mid - 1;
            }
        }
        if (left == right)
        {
            if (nums[left] == target)
            {
                res[0] = left;
                res[1] = right;
            }
        }
    }
};