class Solution {
public:
    //˫ָ��
    //�ܽӵ���ˮȡ���ڵ�ǰλ�ø߶�����߸߶ȵĲ�ֵ
    //���������߱�����ֱ��left==right��ά��left_max��right_max��ֵ
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)
            return 0;
        int left = 0, right = n - 1;
        int res = 0;
        int left_max = -1, right_max = -1;
        while (left < right)
        {   
            //��left_max<right_max�����ˮ������������㣬��ˮȡ����left_max�뵱ǰheight�Ĳ�ֵ
            if (height[left] < height[right])           
            {
                if (height[left] > left_max)    //���ǲ������л�ˮ�ģ�����Ҫ����left_max
                    left_max = height[left];
                else
                    res += left_max - height[left];
                left++;
            }
            //��֮��ͬ
            else
            {
                if (height[right] > right_max)
                    right_max = height[right];
                else
                    res += right_max - height[right];
                right--;
            }
        }
        return res;
    }
};


//˫ָ���:
class Solution {
public:
    //˫ָ��
    //�ܽӵ���ˮȡ���ڵ�ǰλ�ø߶�����߸߶ȵĲ�ֵ
    //���������߱�����ֱ��left==right��ά��left_max��right_max��ֵ
    //����һ����ĳ��λ��i�������ܴ��ˮ��ȡ�������������ߵ����ֵ�н�С��һ����
    //������������Ǵ������Ҵ���left�±�ʱ����ߵ����ֵleft_max���������ǿ��ŵģ���right_max���������ǲ����ŵġ�������ͼ�������м�״��δ֪������left�±���ԣ�right_maxδ�ؾ������ұ�����ֵ��
    //�������������Ǵ���������right�±�ʱ���ұߵ����ֵright_max���������ǿ��ŵģ���left_max���������ǲ����ŵġ�
    /*����λ��left���ԣ���������ֵһ����left_max���ұ����ֵ�����ڵ��ڡ�right_max����ʱ�����left_max<right_max������
    ��ô����֪���Լ��ܴ����ˮ�ˡ������ұ߽����᲻����ָ����right_max������Ӱ����������
    ���Ե�left_max<right_maxʱ�����Ǿ�ϣ��ȥ����left�±꣬��֮������ϣ��ȥ����right�±ꡣ*/
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)
            return 0;
        int left = 0, right = n - 1;
        int res = 0;
        int left_max = 0, right_max = 0;
        while (left < right)
        {
            //��left_max<right_max�����ˮ������������㣬��ˮȡ����left_max�뵱ǰheight�Ĳ�ֵ
            if (left_max < right_max)
            {
                if (height[left] > left_max)    //���ǲ������л�ˮ�ģ�����Ҫ����left_max
                    left_max = height[left];
                else
                {
                    res += left_max - height[left];
                    left++;
                }
            }
            //��֮��ͬ
            else
            {
                if (height[right] > right_max)
                    right_max = height[right];
                else
                {
                    res += right_max - height[right];
                    right--;
                }
            }
        }
        return res;
    }
};
//��̬�滮
class Solution {
public:
    //��̬�滮ά����ǰλ�õ�left_max��right_max
    //��ǰλ���ܽ���ˮ������=min(left_max,right_max)-height[i]
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)
            return 0;
        vector<int> left(n);    //��ǰλ�õ�left_max��right_max
        vector<int> right(n);
        int res = 0;
        left[0] = height[0];
        right[n - 1] = height[n - 1];
        for (int i = 1;i < n;i++)
            left[i] = max(left[i - 1], height[i]);   //��ǰλ�õ�left_max=ǰһ��λ�õ�left_max�͵�ǰ�߶ȵĽϴ���
        for (int i = n - 2;i >= 0;i--)
            right[i] = max(right[i + 1], height[i]);
        for (int i = 1;i < n;i++)
            res += min(left[i], right[i]) - height[i];
        return res;
    }
};