class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        return "1";
        if(n==2)
        return "11";
        string s="11";
        
        for(int k=3;k<=n;k++)
        {
            string t="";
            int c=1;
            s+='&';
            for(int i=1;i<s.size();i++){
            if(s[i]!=s[i-1])
            {
                t=t+to_string(c);
                t=t+s[i-1];
                c=1;
            }
            else
            c++;
        }
        s=t;
        }
    return s;
    }
};