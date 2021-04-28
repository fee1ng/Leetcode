class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> window;     //��������
        int maxLen=0;
        int left=0,right=0;
        while(right<s.size())
        {
            char c1=s[right];
            window[c1]++;
            right++;
            while(window[c1]>1)         //���ظ��ַ������ڿ�ʼ����
            {
                char c2=s[left];
                window[c2]--;
                left++;
            }
            maxLen=max(maxLen,right-left);  //������ִ��ĳ���
        }
        return maxLen;
    }
};