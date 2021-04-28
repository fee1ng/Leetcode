class Solution {
public:
    //res+=num[i]*pow(10,n-i-1)
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if (n == 0)
            return {};
        int i = n - 1;
        digits[i]++;
        int carry = 0;
        while (i >= 1 && digits[i] >= 10)
        {
            carry = 1;
            digits[i] = digits[i] % 10;
            i--;
            digits[i] += carry;
            carry = 0;
        }
        if (digits[0] >= 10)
        {
            carry = 1;
            digits[0] = digits[0] % 10;
            digits.push_back(0);
            for (int i = n;i >= 1;i--)
                digits[i] = digits[i - 1];
            digits[0] = carry;
        }
        return digits;
    }
};