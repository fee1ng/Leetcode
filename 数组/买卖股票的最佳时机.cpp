class Solution {
public:
    //�ҵ���ǰ��֮ǰ����ͼ۸���������ǵ�ǰ�۸�-��ͼۻ�֮ǰ���������
    //�����ҵ���ǰ����֮ǰ����ͼۣ���̬�����������
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;   //��i��ǰ����ͼ۸�
        int maxRes = 0;           //��ǰ�������
        for (auto price : prices)
        {
            maxRes = max(maxRes, price - minPrice);  //��ǰ����������ǵ�ǰ�۸�-��ͼ۾���֮ǰ���������
            minPrice = min(price, minPrice);   //������ͼ۸�
        }
        return maxRes;
    }
};