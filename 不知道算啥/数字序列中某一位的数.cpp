class Solution {
public:
    int findNthDigit(int n) {
        int curr = -1;
        int res = 0;
        for (int i = 0;i < INT_MAX;i++)
        {
            curr += bitOfNum(i);
            if (curr >= n)
            {
                res = getBit(i, curr - n);
                break;
            }
        }
        return res;
    }
    int bitOfNum(int n)
    {
        if (n == 0)
            return 1;
        int res = 0;
        while (n > 0)
        {
            res++;
            n = n / 10;
        }
        return res;
    }
    int getBit(int n, int k)
    {
        int res = 0;
        if (k == 0)
            return n % 10;
        for (int i = 0;i <= k;i++)
        {
            res = n % 10;
            n = n / 10;
        }
        return res;
    }
};