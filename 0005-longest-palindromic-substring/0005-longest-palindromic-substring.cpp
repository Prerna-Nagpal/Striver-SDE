class Solution {
public:
    string longestPalindrome(string s) {
        string maxpalin(1,s[0]);
        for(int i=0;i<s.size();i++){
            string odd = expandAroundCenter(s,i,i);
            string even = expandAroundCenter(s,i,i+1);
            if(odd.size()>=maxpalin.size()) maxpalin=odd;
            if(even.size()>=maxpalin.size()) maxpalin=even;
        }
        return maxpalin;
        
    }
    string expandAroundCenter(string s,int left,int right){
        int n = s.size();
        while(left>=0 && right<n && s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,(right-left-1));
    }
};