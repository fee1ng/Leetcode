class Solution {
public:
    //¿ìËÙÃİ
    double myPow(double x, int n) {
        if (x == 1 || n == 0)
            return 1;
        int flag = 0;
        long num = n;
        if (n < 0)
        {
            flag = 1;
            num = -num;
            x = 1 / x;
        }
        double res = 1;
        while (num > 0)
        {
            if (num % 2 == 1)
            {
                res *= x;
            }
            num = num >> 1;
            x *= x;
        }

        return res;
    }
};