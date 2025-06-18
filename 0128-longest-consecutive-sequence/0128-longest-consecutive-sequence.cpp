class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n  = nums.size();
        if(n==0) return 0;
        int longest = 1;
        unordered_set<int> st;
        int cnt = 0;
        int x = 0;
        for(int i=0;i<n;i++) st.insert(nums[i]);
        for(auto it : st){
            if(st.find(it-1) == st.end()){
                cnt =1;
                x = it;
            }
            while(st.find(x+1) != st.end()){
                x=x+1;
                cnt++;
            }
            longest = max(longest,cnt);
        }
        return longest;
        
    }
};