class Solution {
public:
    //���Ȱ���ÿ���������Ԫ�ش�С��������
    //��������Ժϲ����䣬��ǰһ��������Ҷ˵�ֵ<��һ���������˵�ֵ
    //��������Ժϲ�����,��Ҫ�����Ҷ˵�Ϊǰһ�������Ҷ˵����һ�������Ҷ˵�Ľϴ�ֵ
    //��˵㲻��Ҫ������Ϊ�Ѿ��������
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (int i = 0;i < size;i++)
        {
            int L = intervals[i][0];
            int R = intervals[i][1];
            if (!res.size() || res.back()[1] < L)
                res.push_back({ L,R });
            else
                res.back()[1] = max(R, res.back()[1]);
        }
        return res;
    }
};