class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        dp[1][0]=1;
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(obstacleGrid[i-1][j-1]==0)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};