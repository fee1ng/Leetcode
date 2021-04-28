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
    //建立一个multiset(红黑树)储存最小的k个数，一次遍历，分情况讨论
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 0)
            return {};
        multiset<int, greater<int>> s;
        int sum = 0;
        for (int i = 0;i < n;i++)
        {
            //若容器还没满，则将数都放进容器
            if (sum < k)
            {
                sum++;
                s.insert(arr[i]);
            }
            //若满了，则需要替换，容器最大的数在第一个，则只需比较当前数是否小于容器内的最大值，若小于，则插入
            //注意set的删除与插入操作
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