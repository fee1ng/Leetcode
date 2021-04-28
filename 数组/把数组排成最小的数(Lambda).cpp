/*֤�����������ַ��������������������С��
* ����������������ΪA1 A2 ........ Ax........Ay......An����ΪM
*���ʽ�Ӳ�����С�ģ������x,y����ʹ��A1 A2 ......Ay......Ax.....An<A1 A2....Ax...Ay...An
* ����A1 A2 ......Ay......Ax.....An��ΪN��������N<M
* ��M��Ay�������ƣ�ֱ�����Ƶ�Ax֮ǰ����ΪP������Ax<Ay�����ִ��ǰ�ƣ���19->91��������M<P
* ͬ����P�е�Ax���ƣ�ֱ�����Ƶ�A(y-1)֮������С���Ƶ����棬��ζ�����ִ��ǰ�ƣ���19->91,�ƶ��꼴ΪN����P<N
* ����M<P,P<N  =>>  M<N������費��
* ����MΪ��С�ģ���������������������������С��
*/

string minNumber(vector<int>& nums) {
    vector<string>strs;
    string ans;
    for (int i = 0; i < nums.size(); i++) {
        strs.push_back(to_string(nums[i]));
    }
    sort(strs.begin(), strs.end(), [](string& a, string& b) {return a + b < b + a;});   //lambda����˼a+b<b+a,��a<b
    for (int i = 0; i < strs.size(); i++)
        ans += strs[i];
    return ans;
}

class Solution {
public:

    //��������m,n��ƴ�ӳ�mn��nm�����ݴ�С�Ƚ������С��
    //��������m,n��ƴ�ӳ�mn��nm�����mn>nm������n<m����֮m>n
    //������תΪһ���ַ������飬�ٶ��ַ�����������¶���Ĵ�С����
    string minNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return"";
        string res;
        vector<string> s;
        //��ת��Ϊ�ַ������飬�ٸ����µĴ�С��������
        for (int i = 0;i < n;i++)
            s.push_back(to_string(nums[i]));
        //��������
        quicksort(s, 0, s.size() - 1);
        for (int i = 0;i < s.size();i++)
            res += s[i];
        return res;
    }
    void quicksort(vector<string>& s, int L, int R)
    {
        if (L < R)
        {
            int mid = help(s, L, R);
            quicksort(s, L, mid - 1);
            quicksort(s, mid + 1, R);
        }
    }
    int help(vector<string>& nums, int L, int R)
    {
        string key = nums[L];
        int i = L + 1, j = R;
        while (1)
        {
            while (i <= j && (compare(nums[i], key)))
                i++;
            while (i <= j && (!compare(nums[j], key)))
                j--;
            if (i > j)
                break;
            swap(nums[i], nums[j]);
        }
        swap(nums[j], nums[L]);
        return j;
    }
    //�µıȽϹ���,a+b>b+a��a>b�ȼ���
    //�ַ���a+b���ַ���b+a������������ַ���ȣ���ASCIIֵ��С��Ƚϣ���ֱ�����ֲ�ͬ���ַ�����'\0'Ϊֹ��
    //��str1=str2���򷵻��㣻��str1<str2���򷵻ظ�������str1>str2���򷵻�����
    //��������strcmp��������Ҫ��.c_str()������stringת��Ϊchar*
    bool compare(string& a, string& b)
    {
        string tmpA = a + b;
        string tmpB = b + a;
        if (strcmp(tmpA.c_str(), tmpB.c_str()) > 0)
            return false;
        else
            return true;
    }

class Solution {
public:
    //��������m,n��ƴ�ӳ�mn��nm�����mn>nm������n<m����֮m>n
    //������תΪһ���ַ������飬�ٶ��ַ�����������¶���Ĵ�С����
    //��ʹ��ð������
    string minNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return"";
        string res;
        vector<string> s;
        for (int i = 0;i < n;i++)
            s.push_back(to_string(nums[i]));
        for (int i = 0;i < n;i++)
            for (int j = i + 1;j < n;j++)
            {
                //if(s[i]>s[j])
                //swap(s[i],s[j])
                if (!compare(s[i], s[j]))
                {
                    string tmp = s[i];
                    s[i] = s[j];
                    s[j] = tmp;
                }
            }
        for (int i = 0;i < s.size();i++)
            res += s[i];
        return res;
    }
    bool compare(string& a, string& b)
    {
        int LA = a.size();
        int LB = b.size();
        if (LA == 0)
            return false;
        if (LB == 0)
            return true;
        double sum_a = 0, sum_b = 0;
        int n = LA + LB;
        string tmpA = a + b;
        for (int i = n - 1;i >= 0;i--)
        {
            sum_a = (tmpA[i] - '0') * pow(10, n - i - 1) + sum_a;
        }
        string tmpB = b + a;
        for (int j = n - 1;j >= 0;j--)
        {
            sum_b = (tmpB[j] - '0') * pow(10, n - j - 1) + sum_b;
        }
        if (sum_a > sum_b)
            return false;
        else
            return true;
    }
    /*string minNumber(vector<int>& nums) {
        vector<string>strs;
        string ans;
        for(int i = 0; i < nums.size(); i ++){
            strs.push_back(to_string(nums[i]));
        }
        sort(strs.begin(), strs.end(),[](string&a,string&b){return a+b<b+a;});
        for(int i = 0; i < strs.size(); i ++)
            ans += strs[i];
        return ans;
    }*/
};