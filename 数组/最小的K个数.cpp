class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        //O(nlogn)
        if (arr.size() == 0)
            return {};
        sort(arr.begin(), arr.end());
        vector<int> res;
        for (int i = 0;i < k;i++)
            res.push_back(arr[i]);
        return res;
    }
};



class Solution {
public:
    //O(nlogk)
    //����һ��multiset(�����)������С��k������һ�α��������������
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 0)
            return {};
        multiset<int, greater<int>> s;
        int sum = 0;
        for (int i = 0;i < n;i++)
        {
            //��������û�����������Ž�����
            if (sum < k)
            {
                sum++;
                s.insert(arr[i]);
            }
            //�����ˣ�����Ҫ�滻�������������ڵ�һ������ֻ��Ƚϵ�ǰ���Ƿ�С�������ڵ����ֵ����С�ڣ������
            //ע��set��ɾ����������
            else
            {
                auto it = s.begin();
                if (arr[i] < *it)
                {
                    s.erase(it);
                    s.insert(arr[i]);
                }
            }
        }
        vector<int> res;
        for (auto num : s)
        {
            res.push_back(num);
        }
        return res;
    }
};