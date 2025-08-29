class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(auto it:s) mp[it]++;
        int maxi=-1e9;
        string ans="";
        char ch;
        for(int i=0;i<mp.size();i++){
            for(auto it:mp){
                if(it.second>maxi){
                    maxi=it.second;
                    ch=it.first;
                }
            }
            while(maxi>0){
                ans+=ch;
                maxi--;
            }
            mp[ch]=0;
        }
        return ans;
        
        
    }

};