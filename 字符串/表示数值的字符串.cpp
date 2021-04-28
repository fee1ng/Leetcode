class Solution {
public:
    //�����ַ������Էֳ������֣���������A  С������B  ָ������C  �м���'.'��'e/E'����
    //��Ҫע���ų��ַ���ǰ��ͺ���Ŀո����жϳɹ�������Ϊres=true���Ѿ������������ַ���������" 1. 3"=false
    //�����������A,B,C���ֵ��жϹ�������
    //1.A��C������'+'��'-'��ͷ��0-9����λ����B��0-9����λ������ǰ�治����������
    bool isNumber(string s) {
        int n = s.size();
        if (n == 0)
            return false;
        int index = 0;
        //�ų���ͷ�Ŀո�
        while (s[index] == ' ')
            index++;
        //�ж��Ƿ�Ϊ��������
        bool res = isInt(s, index);

        //�ж��Ƿ�ΪС������
        //1.С�����ֿ���û���������֣���.123=0.123
        //2.С�������Ҳ����û�����֣���233.=233.0
        //3.С����ǰ��ͺ�����Զ������֣���233.666
        if (s[index] == '.')
        {
            index++;
            res = isUnsignInt(s, index) || res;  //С���������������֣�������||�Ĺ�ϵ
        }

        //�ж��Ƿ�Ϊָ������
        //1.���e/Eǰ��û�����֣��������ַ������ܱ�ʾ���֣���e9
        //2.���e/E��û�����������ܱ�ʾ���֣���12e��12e+5.4
        if (s[index] == 'e' || s[index] == 'E')
        {
            index++;
            res = isInt(s, index) && res;        //ָ������ǰ������������������&&
        }

        //ȥ�����Ŀո�
        while (s[index] == ' ')
            index++;
        //����ֵ������Ϊ����Ѿ���鵽���һλ��res=true
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
        //index>before,˵����0-9������
        return index > before;
    }
};