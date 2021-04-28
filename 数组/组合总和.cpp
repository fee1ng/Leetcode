class Solution {
public:
    //���ݱ���һ�Ŷ���������A.ѡ��ǰ��nλ���֣�B.��ѡ���������ѡ���n+1����������֦
    //��������������˳�����Ϊtarget==0,���ҵ�������������鱻���ꡣ
    //���鱻����ļ������Ӽ������е�ÿ��������ѡ����ô�����target���ڣ�����Ҫ�˳�����Ϊû��ѡ�ˡ�
    //��nλ�����Կ����û��ã���ѡ����б�����һ����ڵ�ǰ����г���
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        if (n == 0)
            return res;
        vector<int> v;
        help(candidates, target, v, 0);
        return res;
    }
    void help(vector<int>& candidates, int target, vector<int>& v, int n)
    {
        if (n == candidates.size())
            return;
        if (target == 0)
        {
            res.push_back(v);
            return;
        }
        help(candidates, target, v, n + 1);  //��ѡ��n����
        //ѡ��n����
        if (candidates[n] <= target)
        {
            target -= candidates[n];
            v.push_back(candidates[n]);
            help(candidates, target, v, n);     //�´λ������￪ʼ����Ϊ���ֿ����ظ�ʹ��
            v.pop_back();
        }
    }
};


class Solution {
public:
    vector<vector<int>> res;
    //���ݱ���һ��candidates.size()-index����
    //ȥ�ط�����ͬһ��ĵڶ����ڵ��Ժ󲻱���֮ǰ�ڵ��Ѿ�����������������:
    //[2,3,6,7]�ĵڶ���ڶ����ڵ�3���ٽ�2���볢�������С�����ȥ[2,2,3]���ظ�[3,2,2]
    //[2,3,6,7]�ĵ�����ڶ������ڵ�3���ٱ���2������ȥ[2,2,3]���ظ�[2,3,2]
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, v, 0);
        return res;
    }
    void dfs(vector<int>& candidates, int  target, vector<int>& v, int index)
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
            if (candidates[i] <= target)
            {
                v.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], v, i);
                v.pop_back();
            }
        }
    }
};