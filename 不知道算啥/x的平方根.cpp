class Solution {
public:
    int mySqrt(int x) {
        int res = 0;
        int left = 0;
        int right = x;
        while (left <= right)
        {
            long long mid = (left + right) / 2;
            long long tmp = mid * mid;
            if (tmp > x)
                right = mid - 1;
            else if (tmp < x)
            {
                left = mid + 1;
                res = mid;
            }
            else
                return mid;
        }
        return res;
    }
};