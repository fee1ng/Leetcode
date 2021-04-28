class Solution {
public:
    //整个字符串可以分成三部分，整数部分A  小数部分B  指数部分C  中间由'.'或'e/E'隔开
    //需要注意排除字符串前面和后面的空格，且判断成功的条件为res=true且已经遍历完整个字符串，例如" 1. 3"=false
    //根据题意给出A,B,C部分的判断规则如下
    //1.A和C都是以'+'或'-'开头的0-9的数位串，B是0-9的数位串，但前面不能有正负号
    bool isNumber(string s) {
        int n = s.size();
        if (n == 0)
            return false;
        int index = 0;
        //排除开头的空格
        while (s[index] == ' ')
            index++;
        //判断是否为整数部分
        bool res = isInt(s, index);

        //判断是否为小数部分
        //1.小数部分可以没有整数部分，如.123=0.123
        //2.小数点后面也可以没有数字，如233.=233.0
        //3.小数点前面和后面可以都有数字，如233.666
        if (s[index] == '.')
        {
            index++;
            res = isUnsignInt(s, index) || res;  //小数部分允许不带数字，所以是||的关系
        }

        //判断是否为指数部分
        //1.如果e/E前面没有数字，则整个字符串不能表示数字，如e9
        //2.如果e/E后没有整数，则不能表示数字，如12e，12e+5.4
        if (s[index] == 'e' || s[index] == 'E')
        {
            index++;
            res = isInt(s, index) && res;        //指数部分前必须有整数，所以是&&
        }

        //去除最后的空格
        while (s[index] == ' ')
            index++;
        //是数值的条件为最后已经检查到最后一位且res=true
        return (res && index == n);
    }
    bool isInt(string& s, int& index)
    {
        if (s[index] == '+' || s[index] == '-')
            index++;
        return isUnsignInt(s, index);
    }
    bool isUnsignInt(string& s, int& index)
    {
        int before = index;
        while (index < s.size() && s[index] >= '0' && s[index] <= '9')
        {
            index++;
        }
        //index>before,说明有0-9的数字
        return index > before;
    }
};