class Solution {
public:
//TC->O(2^n)+O(k)=O(2^n*k)
//SC->O(2^n*k)
void helper(int ind,vector<int>& nums,vector<vector<int>>& ans,vector<int>& ds){
    ans.push_back(ds);
    for(int i=ind;i<nums.size();i++){
        if(i!=ind && nums[i]==nums[i-1]) continue;
        ds.push_back(nums[i]);
        helper(i+1,nums,ans,ds);
        ds.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        helper(0,nums,ans,ds);
        return ans;
        
    }
};