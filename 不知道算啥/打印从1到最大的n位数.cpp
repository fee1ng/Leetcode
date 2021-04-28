#include <iostream>
#include <string>
#include <vector>
using namespace std;

//������Ҫ���Ǵ��������⣬�����ַ����洢ÿһ������ģ���ַ����ӷ����ַ����е�ȫ����
class Solution {
public:
    //ȫ���У�����nλ��ʮ��������ʵ����n��0-9��ȫ����
    vector<int> res;
    vector<int> printNumbers(int n) {
        vector<int> v;
        dfs(n,v);
        return res;
    }
    void dfs(int n,vector<int>& v)
    {   
        //�˳�����Ϊ�Ѿ�������nλ��
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
        //����ȫ���У���ǰλ����ѡ0-9������һ����
        for(int i=0;i<10;++i)
        {
            v.push_back(i);
            dfs(n,v);   //������һλ����
            v.pop_back();   //��һλ������λ����
        }    
    }
};

//���Ǵ�������ȫ����
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
    //indexΪ��ǰ���е��ڼ�λ��
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


//�����nλ������sum����ӡ��1-sum��ÿһλ�������Ǵ�����
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