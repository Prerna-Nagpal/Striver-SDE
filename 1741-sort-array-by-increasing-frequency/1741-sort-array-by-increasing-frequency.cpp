class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[nums[i]]++;
        priority_queue<pair<int,int>> maxh;
        for(auto it = mp.begin();it!=mp.end();it++) maxh.push({-it->second,it->first});
        vector<int>ans;
        while(maxh.size()>0){
            int freq = maxh.top().first;
            int ele = maxh.top().second;
            for(int i=0;i<abs(freq);i++) ans.push_back(ele);
            maxh.pop();
        }
        return ans;
    }
};