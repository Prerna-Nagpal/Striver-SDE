class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();//stores the size of og array
    set<int>st(nums.begin(),nums.end());//contains unique and ascending elem
    vector<int>nums2(st.begin(),st.end());
    int m=nums2.size();
    int dp[n+1][m+1];//you declare a dp
    //now comes the initialzation part
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
        }
    }
    //this is lcs now, nothing new ;)
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(nums[i-1]==nums2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    //AV for the president \U0001f480
    return dp[n][m];
}
};