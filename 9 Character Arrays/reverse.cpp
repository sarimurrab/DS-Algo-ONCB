class Solution {
public:
    string reverseWords(string s) {
        string gl = "";
        for(int i=0;i<s.length();i++)
        {
            string loc = "";
            while(s[i]!=' ' && i<s.length())
            {
                loc = s[i]+loc;
                i++;
            }
            gl = gl+loc;
            if(i!=s.length())
                gl += ' ';
        }
        
        return gl;
    }
};

