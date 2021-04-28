class Solution {
public:
    //�½��ռ䣬����ԭ�ַ������޸ġ�
    string replaceSpace(string s) {
        string res;
        string tmp;
        for (auto c : s)
        {
            if (c != ' ')
                tmp += c;
            if (c == ' ')
            {
                tmp += "%20";
                res += tmp;
                tmp = "";
            }
        }
        res += tmp;
        return res;
    }
};

class Solution {
public:
    //���½��ռ䣬��ԭ�ַ������޸�
    string replaceSpace(string s) {
        int L = s.size();
        int space = 0;    //ͳ���м����ո�
        //��һ�α���ͳ���м����ո񣬸����޸ĺ���ַ����ĳ���
        //һ���ո񳤶�+2
        for (auto c : s)
        {
            if (c == ' ')
                space++;
        }

        int realL = L + 2 * space;
        s.resize(realL);

        //����ָ�룬һ��ָ�����ַ�����ĩβ��һ��ָ��ԭ���ַ�����ĩβ
        int j = realL - 1, i = L - 1;
        while (i >= 0)
        {
            //���ǿո�����
            if (s[i] != ' ')
            {
                s[j] = s[i];
                j--;
                i--;
            }
            //�ǿո����滻
            else if (s[i] == ' ')
            {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
                i--;
            }
        }
        return s;
    }
};