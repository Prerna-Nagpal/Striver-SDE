class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[1],nums[0]);
        vector<int>v(n-1,-1);
        v[0]=nums[1];
        v[1]=max(nums[1],nums[2]);
        for(int i=2;i<n-1;i++){
            v[i]=max(v[i-2]+nums[i+1],v[i-1]);
        }
        int x=v[n-2];
        v[0]=nums[0];
        v[1]=max(nums[0],nums[1]);
        for(int i=2;i<n-1;i++){
            v[i]=max(v[i-2]+nums[i],v[i-1]);
        }
        return max(v[n-2],x);
    }
};