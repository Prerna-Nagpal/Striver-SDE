class Solution {
public:
void helper(string& s,set<string>& dict,int ind,string ds,vector<string>& ans){
    if(ind>=s.size()){
        ds.pop_back();
        ans.push_back(ds);
        return;
    }
    for(int i=ind;i<s.size();i++){
        string word = s.substr(ind,i-ind+1);
        if(dict.find(word)!=dict.end())
        helper(s,dict,i+1,ds+word+" ",ans);
    }
}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        set<string>dict(wordDict.begin(),wordDict.end());
        helper(s,dict,0,"",ans);
        return ans;


    }
};