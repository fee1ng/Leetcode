//����һ���ַ��� S��һ���ַ��� T ���������һ���㷨�������� O(n) ��ʱ�临�Ӷ��ڣ����ַ��� S �����ҳ������� T �����ַ�����С�Ӵ���
class Solution {
public:
    //��������
    //����right��������������Сleft��right�ľ���
    string minWindow(string s, string t) {
        //��window��Ӧ�ַ����ֵĴ�������need���ֵĴ�����˵�����Գɹ�
        unordered_map<char, int> window;
        unordered_map<char, int> need;
        int match=0;    //��ǰ�Ѿ������������ַ�����
        int minLen=INT_MAX;
        int left=0,right=0;
        int start=0;    //�ִ������
        //��Ŀ���ִ��ַ��ĸ���ͳ��
        for(int i=0;i<t.size();i++)
        {
            need[t[i]]++;
        }
        while(right<s.size())
        {
            char tmp=s[right];
            if(need.count(tmp)) //������ַ���Ҫ���
            {
                window[tmp]++;
                if(window[tmp]==need[tmp])
                    match++;
            }
            right++;
            //����С�ִ�
            while(match==need.size())       //˵��Ҫ���ִ��Ѿ�ȫ�����֣�����С����ִ��ĳ���
            {
                //������С�ִ���λ���볤��
                if(minLen>right-left)
                {
                    start=left;
                    minLen=right-left;
                }
                char c2=s[left];
                //��ֹ����ͷ
                if(need.count(c2))
                {
                    window[c2]--;
                    if(need[c2]>window[c2])
                        match--;
                }
                left++;
            }
        }
        return minLen == INT_MAX ?
                "" : s.substr(start, minLen);
    }
};