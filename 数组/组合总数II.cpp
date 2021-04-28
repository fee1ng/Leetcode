class Solution {
public:
    //ÿ��Ԫ��ֻ��ʹ��һ�Σ�˵��ÿ��ѡ��ı����������ʼ�±�index֮ǰ��������ʹ��
     //[2,3,6,7] index=1ʱ��ֻ������ѡ�񣬼�3,6,7
    //�⼯�������ظ���ϣ�����Ҫ�����������������ǰ����������==ǰһ�α��������֣�������
    //[2,2,3,6,7],��ʼroot�ڵ������һ��2������i=1��Ҫ�����ڶ���2ʱҪȥ�أ���continue
    //���ݱ���һ��candidates.size()-index������ע������ȥ��
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        if (n == 0)
            return res;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        help(candidates, target, v, 0);
        return res;
    }
    void help(vector<int>& candidates, int target, vector<int>& v, int index)
    {
        if (target == 0)
        {
            res.push_back(v);
            return;
        }
        if (index == candidates.size())
            return;
        for (int i = index;i < candidates.size();i++)
        {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] <= target)
            {
                v.push_back(candidates[i]);
                help(candidates, target - candidates[i], v, i + 1);
                v.pop_back();
            }
            else
                break;
        }
    }
};