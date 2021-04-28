class Solution {
public:
    //首先按照每个区间的首元素大小进行排序
    //如果不可以合并区间，则前一个区间的右端点值<下一个区间的左端点值
    //否则则可以合并区间,需要更新右端点为前一个区间右端点和下一个区间右端点的较大值
    //左端点不需要更新因为已经排序过了
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