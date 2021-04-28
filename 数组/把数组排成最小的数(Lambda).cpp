/*证明排完序后的字符串数组组合起来就是最小的
* 设排完序的数字组合为A1 A2 ........ Ax........Ay......An，记为M
*设该式子不是最小的，则存在x,y互换使得A1 A2 ......Ay......Ax.....An<A1 A2....Ax...Ay...An
* 其中A1 A2 ......Ay......Ax.....An记为N，即假设N<M
* 对M中Ay进行左移，直到左移到Ax之前，记为P，由于Ax<Ay，数字大的前移，如19->91，所以有M<P
* 同理，对P中的Ax右移，直到右移到A(y-1)之后，数字小的移到后面，意味着数字大的前移，如19->91,移动完即为N，有P<N
* 所以M<P,P<N  =>>  M<N，与假设不符
* 所以M为最小的，即排完序后数组组合起来就是最小的
*/

string minNumber(vector<int>& nums) {
    vector<string>strs;
    string ans;
    for (int i = 0; i < nums.size(); i++) {
        strs.push_back(to_string(nums[i]));
    }
    sort(strs.begin(), strs.end(), [](string& a, string& b) {return a + b < b + a;});   //lambda，意思a+b<b+a,则a<b
    for (int i = 0; i < strs.size(); i++)
        ans += strs[i];
    return ans;
}

class Solution {
public:

    //两个数字m,n能拼接成mn或nm，根据大小比较输出较小的
    //两个数字m,n能拼接成mn或nm，如果mn>nm，定义n<m，反之m>n
    //将数组转为一个字符串数组，再对字符串数组根据新定义的大小排序
    string minNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return"";
        string res;
        vector<string> s;
        //先转换为字符串数组，再根据新的大小规则排序
        for (int i = 0;i < n;i++)
            s.push_back(to_string(nums[i]));
        //快速排序
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
    //新的比较规则,a+b>b+a则a>b等价于
    //字符串a+b与字符串b+a自左向右逐个字符相比（按ASCII值大小相比较），直到出现不同的字符或遇'\0'为止。
    //若str1=str2，则返回零；若str1<str2，则返回负数；若str1>str2，则返回正数
    //可以利用strcmp函数，需要用.c_str()函数将string转换为char*
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
    //两个数字m,n能拼接成mn或nm，如果mn>nm，定义n<m，反之m>n
    //将数组转为一个字符串数组，再对字符串数组根据新定义的大小排序
    //此使用冒泡排序
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