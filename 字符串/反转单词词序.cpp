string reverseWords(string s) {
    int left = 0, right = 0;
    vector<string> res;
    if (s.size() == 0)
        return "";
    while (right < s.length())
    {
        if (s[left] == ' ')
        {
            left++;
            right++;
            continue;
        }
        while (right < s.size() && s[right] != ' ')
            right++;
        if (right > left || right == s.length())
        {
            string word(s.begin() + left, s.begin() + right);
            res.push_back(word);
            left = right;
            continue;
        }
    }
    if (res.size() == 0)
        return "";
    else if (res.size() == 1)
        return res[0];
    else
    {
        string tmp;
        for (int i = 1;i < res.size();++i)
            tmp += res[res.size() - i] + ' ';
        tmp += res[0];
        return tmp;
    }
}