class Solution {
public:
    string addBinary(string a, string b) {
        //令两个字符串等长，遍历两个字符串，模拟笔算,结果保留在a
        int al = a.size(), bl = b.size();
        while (al < bl)
        {
            a = '0' + a;
            al++;
        }
        while (bl < al)
        {
            b = '0' + b;
            bl++;
        }
        int carry = 0;
        int i;
        for (i = a.size() - 1;i >= 0;i--)
        {
            int s = a[i] - '0' + b[i] - '0' + carry;
            if (s >= 2)
            {
                a[i] = (s - 2) + '0';
                carry = 1;
            }
            else
            {
                carry = 0;
                a[i] = s + '0';
            }
        }
        if (carry == 1)
            a = '1' + a;
        return a;
    }
};