class Solution {
public:
    //动态规划
    //dp[i]表示以nums[i]结尾的字串的最大和
    int maxSubArray(vector<int>& nums) {
        int size=nums.size();
        vector<int> dp(size);
        dp[0]=nums[0];
        for(int i=1;i<size;i++)
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
        sort(dp.begin(),dp.end());
        return dp[size-1];
    }
};
//O(1)动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //dymatic plan
        //currSum=max(currSum+nums[i],nums[i])
        //更新res=max(res,currSum)
        int n = nums.size();
        int currSum = 0;
        int m = INT_MIN;
        for (int i = 0;i < n;i++)
        {
            //currSum[i]=max(currSum[i-1]+nums[i],nums[i]);
            currSum = max(currSum + nums[i], nums[i]);
            m = max(currSum, m);
        }
        return m;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //求从某位开始的当前前缀和，当当前的前缀和<=0时，currSum=data[i]
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int currSum = 0;
        int max = INT_MIN;
        for (int i = 0;i < n;i++)
        {
            if (currSum <= 0)
                currSum = nums[i];
            else
                currSum += nums[i];
            if (currSum > max)
                max = currSum;
        }
        return max;
    }
};

//分治
/*
我们定义一个操作 get(a, l, r) 表示查询 aa 序列 [l, r][l,r] 区间内的最大子段和，那么最终我们要求的答案就是 get(nums, 0, nums.size() - 1)。
如何分治实现这个操作呢？对于一个区间 [l, r][l,r]，我们取m=(l+r)/2
​对区间 [l, m][l,m] 和 [m + 1, r][m+1,r] 分治求解。当递归逐层深入直到区间长度缩小为 1 的时候，递归「开始回升」。
这个时候我们考虑如何通过 [l, m]区间的信息和 [m + 1, r] 区间的信息合并成区间 [l, r]的信息。最关键的两个问题是：

我们要维护区间的哪些信息呢？
我们如何合并这些信息呢？
对于一个区间 [l, r][l,r]，我们可以维护四个量：

lSum 表示 [l, r] 内以 l 为左端点的最大子段和
rSum 表示 [l, r] 内以 r 为右端点的最大子段和
mSum 表示 [l, r] 内的最大子段和
iSum 表示 [l, r] 的区间和
以下简称 [l, m] 为 [l, r] 的「左子区间」，[m + 1, r] 为 [l, r]的「右子区间」。
我们考虑如何维护这些量呢（如何通过左右子区间的信息合并得到 [l, r] 的信息）？
对于长度为 1的区间 [i, i]，
四个量的值都和a[i]相等​。

对于长度大于 1 的区间：
首先最好维护的是 iSum，区间 [l, r][l,r] 的 iSum 就等于「左子区间」的 iSum 加上「右子区间」的 iSum。
对于 [l, r]的 lSum，存在两种可能，它要么等于「左子区间」的 lSum，要么等于「左子区间」的 iSum 加上「右子区间」的 lSum，二者取大。
对于 [l, r]的 rSum，同理，它要么等于「右子区间」的 rSum，要么等于「右子区间」的 iSum 加上「左子区间」的 rSum，二者取大。
当计算好上面的三个量之后，就很好计算 [l, r]的 mSum 了。我们可以考虑 [l, r][l,r] 的 mSum 对应的区间是否跨越 m——它可能不跨越 m，
也就是说 [l, r] 的 mSum 可能是「左子区间」的 mSum 和 「右子区间」的 mSum 中的一个；
它也可能跨越 m，可能是「左子区间」的 rSum 和 「右子区间」的 lSum 求和。三者取大。

*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //分治
        int n = nums.size();
        return get(nums, 0, n - 1).mSum;
    }
    struct data
    {
        int Lsum, Rsum, mSum, iSum;
    };
    //在去间[l,r]更新data数据
    data PushUp(data l, data r)
    {
        int iSum = l.iSum + r.iSum;
        int lsum = max(l.Lsum, l.iSum + r.Lsum);
        int rsum = max(r.Rsum, r.iSum + l.Rsum);
        int mSum = max(max(l.mSum, r.mSum), l.Rsum + r.Lsum);
        return (data) { lsum, rsum, mSum, iSum };
    }
    data get(vector<int>& nums, int l, int r)
    {
        if (l == r)
            return (data) { nums[l], nums[l], nums[r], nums[r] };
        int m = (l + r) / 2;
        data lSub = get(nums, l, m);
        data rSub = get(nums, m + 1, r);
        return PushUp(lSub, rSub);
    }
};