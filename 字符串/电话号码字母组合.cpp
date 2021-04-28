class Solution {
public:
    //����
    //���ݹ�ϣ�������������ַ�����Ĺ�ϵ
    //��������digits�ַ�������֪�����ϵ��˳�����Ϊ������digits�ַ���
    //����һ�����֣�����3��Ӧ�����ĸ�����Ա���3��ʱ����Ҫ�����3����Ӧ��������ĸ
    //��Ҫtmp�ַ������浱ǰ��ϵĽ��
    //i Ϊ��ǰ����digits�ַ�����λ��
    //vector����ʹ�����ô��ݣ�ֵ���ݻᵼ�¿մ�
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size()==0)
            return res;
        unordered_map<char, string> m
        {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string tmp;
        help(res,digits,m,0,tmp);
        return res;
    }

    void help(vector<string>& res,string digits,unordered_map<char,string> m,int i,string tmp)
    {
        if(i==digits.length())      //�������ˣ���������������ĸ���뵱ǰ����ַ��������Ա��浱ǰ�����                                       ���������˸��ַ������һ����ĸ
            res.push_back(tmp);
        else
        {
            char c=digits[i];       //�ҵ�����
            string letter=m[c];     //���ֶ�Ӧ����ĸ���
            for(auto c2:letter)     //�����е�ÿ����ĸ�����뵱ǰ����ַ����������´εݹ�
            {
                tmp.push_back(c2);
                help(res,digits,m,i+1,tmp);
                tmp.pop_back();
            }
            //����ab,b���ˣ�ac��c���ˣ�ad    letter="bcd"
        }
    }
};

 vector<string> letterCombinations(string digits) {
        //����������������ĸ"a,b,c",�µ��ַ���"def"
        //���ö����Ƚ��ȳ�����a b c ->ad ae af bd be bf ......
vector<string> res;
if (digits.size() == 0)
return res;
unordered_map<char, string> m
{
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};
res.push_back("");
for (int i = 0;i < digits.size();i++)        //����digits����
{
    char c = digits[i];                      //�ҵ�����
    string letter = m[c];                    //���ֶ�Ӧ���ַ���
    int size = res.size();                   //��ǰ���еĳ��ȣ��Զ������ÿ��Ԫ�ض�������µ����ֶ�Ӧ���ַ����е���ĸ�����
                                             //ÿ��ʹ��ǰһλԪ�س���
    for (int j = 0;j < size;j++)
    {
        vector<string>::iterator itor = res.begin();        //����
        string tmp = *itor;
        res.erase(itor);
        for (int k = 0;k < letter.size();k++)               //���µ��ַ����е���ĸ�����
        {
            res.push_back(tmp + letter.at(k));              //���������
        }
    }
}
return res;
    }