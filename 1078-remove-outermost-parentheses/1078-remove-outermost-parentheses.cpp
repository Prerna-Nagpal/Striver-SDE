class Solution {
public:
    string removeOuterParentheses(string s) {
        int count =0;
        int n = s.size();
        string newstr = "";
        for(int i=0;i<n;i++){
            if(s[i]=='(' && count==0) count++;
            else if(s[i]=='(' && count>=1){
                newstr+=s[i];
                count++;
            }
            else if(s[i]==')' && count >1){
                newstr+=s[i];
                count--;
            }
            else count--;
        }
       return newstr; 
    }
};