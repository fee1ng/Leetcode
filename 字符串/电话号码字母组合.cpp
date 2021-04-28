class Solution {
public:
    //回溯
    //根据哈希表构建出数字与字符串间的关系
    //遍历给定digits字符串，可知随机组合的退出条件为遍历完digits字符串
    //由于一个数字，比如3对应多个字母，所以遍历3的时候需要组合完3所对应的所有字母
    //需要tmp字符串保存当前组合的结果
    //i 为当前遍历digits字符串的位置
    //vector数组使用引用传递，值传递会导致空串
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
        if(i==digits.length())      //遍历完了，不可能再有新字母插入当前结果字符串，所以保存当前结果字                                       符串并回退该字符串最后一个字母
            res.push_back(tmp);
        else
        {
            char c=digits[i];       //找到数字
            string letter=m[c];     //数字对应的字母组合
            for(auto c2:letter)     //对其中的每个字母，插入当前结果字符串并进行下次递归
            {
                tmp.push_back(c2);
                help(res,digits,m,i+1,tmp);
                tmp.pop_back();
            }
            //例，ab,b回退，ac，c回退，ad    letter="bcd"
        }
    }
};

 vector<string> letterCombinations(string digits) {
        //例，队列中现有字母"a,b,c",新的字符串"def"
        //利用队列先进先出，如a b c ->ad ae af bd be bf ......
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
for (int i = 0;i < digits.size();i++)        //遍历digits数组
{
    char c = digits[i];                      //找到数字
    string letter = m[c];                    //数字对应的字符串
    int size = res.size();                   //当前队列的长度，对队列里的每个元素都与这个新的数字对应的字符串中的字母做组合
                                             //每次使最前一位元素出列
    for (int j = 0;j < size;j++)
    {
        vector<string>::iterator itor = res.begin();        //出列
        string tmp = *itor;
        res.erase(itor);
        for (int k = 0;k < letter.size();k++)               //与新的字符串中的字母做组合
        {
            res.push_back(tmp + letter.at(k));              //并加入队列
        }
    }
}
return res;
    }