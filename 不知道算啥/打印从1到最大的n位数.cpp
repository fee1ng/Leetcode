#include <iostream>
#include <string>
#include <vector>
using namespace std;

//该题需要考虑大整数问题，即用字符串存储每一个数，模拟字符串加法或字符串中的全排列
class Solution {
public:
    //全排列，所有n位的十进制数其实就是n个0-9的全排列
    vector<int> res;
    vector<int> printNumbers(int n) {
        vector<int> v;
        dfs(n,v);
        return res;
    }
    void dfs(int n,vector<int>& v)
    {   
        //退出条件为已经排列了n位数
        if(v.size()==n)
        {   
            int curr=0;
            for(int i=0;i<v.size();i++)
                curr=curr*10+v[i];
            if(curr==0)
                return;
            res.push_back(curr);
            return;
        }
        //回溯全排列，当前位可以选0-9的任意一个数
        for(int i=0;i<10;++i)
        {
            v.push_back(i);
            dfs(n,v);   //进入下一位排列
            v.pop_back();   //下一位排完后该位回退
        }    
    }
};

//考虑大整数的全排列
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> res;
void dfs(int n, int index, string& str);
void print(string& str)
{
    string tmp;
    bool isZero = true;
    for (auto c : str)
    {
        if (c != '0' && isZero)
            isZero = false;
        if (!isZero)
            tmp += c;
    }
    res.push_back(tmp);
    return;
}
vector<string> printNumbers(int n) {
    string str;
    dfs(n, 0, str);
    return res;
}
void dfs(int n, int index, string& str)
{
    //index为当前排列到第几位了
    if (index == n)
    {
        print(str);
        //res.push_back(str);
        return;
    }
    for (int i = 0;i < 10;++i)
    {
        str += i + '0';
        dfs(n, index + 1, str);
        str.pop_back();
    }
}
int main()
{
    printNumbers(2);
    for (auto str : res)
    {
        cout << str << endl;
    }
    return 0;
}


//计算出n位最大的数sum，打印从1-sum的每一位，不考虑大整数
class Solution {
public:
    vector<int> printNumbers(int n) {
        int sum = 0;
        for (int i = 1;i <= n;i++)
            sum = sum * 10 + 9;
        vector<int> res;
        for (int i = 1;i <= sum;i++)
            res.push_back(i);
        return res;
    }
};