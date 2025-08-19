class Solution {
public:
int lowerbound(vector<int>& nums,int target,int n){
    int low=0,high=n-1,ans=n;
    while(low<=high){
        int mid = (low+high)/2;
        if(nums[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}
int upperbound(vector<int>& nums,int target,int n){
    int low=0,high=n-1,ans=n;
    while(low<=high){
        int mid = (low+high)/2;
        if(nums[mid]>target){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(2,-1);
        int first = lowerbound(nums,target,n);
        if(first==n || nums[first]!=target) return ans;
        int last = upperbound(nums,target,n)-1;
        ans[0]=first;
        ans[1]=last;
        return ans;
        }

};