class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256,-1);
        int l=0,r=0,maxlen=0;
        int n = s.size();
        while(r<n){
            if(hash[s[r]]!=-1 && hash[s[r]]>=l)
            l=hash[s[r]]+1;
            maxlen = max(maxlen,r-l+1);
            hash[s[r]]=r;
            r++;
        }
        return maxlen;
        
    }
};