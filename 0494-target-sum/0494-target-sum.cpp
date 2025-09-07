class Solution {
public:
int countsubset(vector<int>& nums,int sum,int n){
    if(sum<0) return 0;
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0) t[i][j]=0;
            if(j==0) t[i][j]=1;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(nums[i-1]<=j) t[i][j]=t[i-1][j-nums[i-1]]+t[i-1][j];
            else t[i][j]=t[i-1][j];
        }
    }
    return t[n][sum];
}
        
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sumofarray = accumulate(nums.begin(), nums.end(), 0);
        int sum1=(sumofarray+target)/2;
        if((sumofarray+target)%2!=0 || (sumofarray+target)<0) return 0;
        return countsubset(nums,sum1,n);
    }
};