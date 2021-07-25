/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        stack<int> num_stack;
        stack<string> str_stack;
        int n=s.size();
        int i=0;
        string tmp("[");
        int num=0;
        string curr_word;
        while(i<n)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                //num_stack.push(s[i]);
                num = num * 10 + s[i] - '0';
            }
            else if(s[i]=='[')
            {   
                str_stack.push(curr_word);
                curr_word="";
                num_stack.push(num);
                num=0;
                //str_stack.push(tmp);
            }
            else if(s[i]==']')
            {   
                int n=num_stack.top();
                num_stack.pop();
                for(int i=0;i<n;i++)
                {
                    str_stack.top()+=curr_word;
                }
                curr_word=str_stack.top();
                str_stack.pop();
            }
            else
            {   
                curr_word+=s[i];
            }
            i++;
        }
        return curr_word;
    }
};
// @lc code=end

