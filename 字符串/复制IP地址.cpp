class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        //���ݣ�IPÿһ���޷�Ϊ1λ 2λ 3λ
        //��������������ȱ���
        string str;
        back(s, 0, 0, str);
        return res;
    }
    void back(string s, int count, int index, string& str)
    {
        if (index == s.size() || count == 4)
        {
            if (index == s.size() && count == 4)
                res.push_back(str.substr(0, str.size() - 1));
            return;
        }
        //����ȡ1λ 2λ 3λ����������൱����������dfs
        for (int i = 1;i <= 3;i++)
        {
            if (i + index > s.size())   //Ҫȡ���ַ���ΧԽ��
                return;
            if (s[index] == '0' && i != 1) //��0��ͷ����λ����λIP��
                return;
            if (i == 3 && s.substr(index, i) > "255")   //��λ��ַ������Χ
                return;
            str += s.substr(index, i);     //�洢��ǰ�������������ȱ���
            str.push_back('.');
            back(s, count + 1, index + i, str);
            str = str.substr(0, str.size() - i - 1);   //���ݣ��ص���һ��ڵ�
        }
    }
};