class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //�Ե�һ���ַ���Ϊ��׼������ÿ���ַ�
        //����������ÿ���ַ��������ַ����Ƚ�
        //�˳������������ַ�����ȫ��������ʱ���в�ͬʱ
        //��Ϊ��󹫹�ǰ׺�϶���������̵��ַ�����
        int j=0;
        string res;
        if(strs.size()==0)
            return res;
        int i;
        for(auto ch:strs[0])
        {
            for(i=1;i<strs.size();i++)
            {
                if(j<strs[i].size())
                {   
                    if(strs[i][j]!=ch)
                        return res;
                }
                else
                    return res;
            }
            res+=strs[i-1][j];
            j++;
        }
        return res;
    }
};
string longestCommonPrefix(vector<string>& strs) {
    //���������Ƚ�
    //�õ�ǰ�Ĺ����ִ����к����Ƚϣ��ݹ飩
    if (strs.size() == 0)
        return "";
    string longstr = strs[0];
    for (int i = 1;i < strs.size();i++)
    {
        longstr = help(longstr, strs[i]);
        if (longstr.size() == 0)       //��ǰ������ִ�Ϊ�գ�û�бȽ�����
            break;
    }
    return longstr;
}
string help(string s1, string s2)
{
    int index = 0;
    int L = min(s1.size(), s2.size());
    while (s1[index] == s2[index] && index < L)
        index++;
    return s1.substr(0, index);
}