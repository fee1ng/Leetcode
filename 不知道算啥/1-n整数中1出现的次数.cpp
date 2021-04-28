class Solution {
public:
    //对n的每一位分析从1-n中该位出现1的次数，并以该位分界，左边为高位high，右边为低位low，该位digt，如十位digt=10
    /*
    1.若该位为0，则该位出现1的情况为高位降位，该位设置为1，遍历所有低位，所以该位出现1的次数=high*digt
    以1104为例，假设现在计算1-1104中十位出现1的个数，则十位出现1的范围是0010-1019，即高位从0遍历到10，低位从0到9
    所以十位出现1的次数为11*10(digt)
    2.若该位为1，以1114为例，分析十位，分解为1-1104中十位出现1的次数+1104-1114中十位出现1的个数
    1104-1114中十位出现1的情况依赖于低位，即从0遍历到low(4),所以该位出现1的次数为high*digt+low+1
    3.若该位为2-9，以1124为例，分析十位，可以分解为1-1104中十位出现1的个数+1104-1124中十位出现1的个数
    1104-1124中十位出现1的个数为1110-1119，显然不依赖于低位的4，只是把其降位到1并遍历digt个低位
    所以该位出现1的次数为high*digt+digt
    由于是1-n，所以定某位为1时(假设是十位)，其低位(个位)可以有digt(10)种情况(10,11,12,13,14....19)，所以要乘
    */
    int countDigitOne(int n) {
        long low = 0, digt = 1;
        long cur = n % 10, high = n / 10;
        int res = 0;
        while (high != 0 || cur != 0)
        {
            if (cur == 0)
                res += high * digt;
            else if (cur == 1)
                res += high * digt + low + 1;
            else
                res += high * digt + digt;
            low = low + cur * digt;
            cur = high % 10;
            high = high / 10;
            digt = digt * 10;
        }
        return res;
    }
};