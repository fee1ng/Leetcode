class Solution {
public:
    //��'/'Ϊ�ֽ磬tmp����'/'
    //stack��ֻ�浥��
    string simplifyPath(string path) {
        stack<string> s;
        string tmp;
        path+='/';
        for(auto c:path)
        {
            if(c=='/')
            {   
                if(tmp==".."&&!s.empty())
                    s.pop();
                //else if(tmp==".."&&s.empty())
                    //return "/";
                else if(tmp!=".."&&tmp!="."&&tmp.size()!=0) //�ǵ���
                    s.push(tmp);
                tmp.clear();
            }
            else
                tmp+=c;
        }
        string res;
        while(!s.empty())
        {
            string t=s.top();
            s.pop();
            res="/"+t+res;
        }
        if(res.size()==0)
            res="/";
        return res;
    }
};