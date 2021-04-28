class Solution {
public:
    //���ֲ��ҵĹؼ�:1.���߻��Ұ��Ϊ���Ե�������    2.�Ƿ�С��nums[mid]������������������
    //���ֲ��ҵĹؼ����ڱ��������������в��ң��������������������飬����֪����ǰmid����߻����ұ�����������
    //�ҵ�mid����߻��ұߵ��������飬����������������Ѱ��(ע���������������������target<�����䵫>=������)���Ҳ���������һ�ߴ���
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 1)
        {
            if (nums[0] == target)
                return 0;
            else
                return -1;
        }
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            //���mid������������ģ���ô�Ұ�߱��������
            //�����ȿ���������Ѱ�ҵ��������target<nums[mid]&&nums[0]<=target�������������򶪸��Ұ�ߴ���
            //��[4,5,6,7,0,1,2]Ϊ����һ��ʼmid=3,nums[mid]=6��target=0<nums[mid]��������һ��target����mid����ߣ���Ϊ���������߽��п��ܲ���С
            //������Ҫ�ж���߽��Ƿ��㹻С���ж��Ƿ񶪽����������
            if (nums[0] <= nums[mid])
            {
                if (target < nums[mid] && nums[0] <= target)
                {
                    right = mid - 1;
                }
                else
                    left = mid + 1;
            }
            //��֮���Ұ�����������߱��������ȿ������Ұ��Ѱ�ҵ��������nums[mid]<target&&taget<=nums[n-1]
            //������������𰸱������ߣ���������ȥ����
            else
            {
                if (nums[mid] < target && target <= nums[n - 1])
                {
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};