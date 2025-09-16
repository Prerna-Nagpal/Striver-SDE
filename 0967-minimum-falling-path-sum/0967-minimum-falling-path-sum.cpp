class Solution {
public:
int solve(vector<vector<int>>& matrix,int m,int n){
    int dp[m][n];
    for(int i=0;i<n;i++) dp[0][i]=matrix[0][i];
    for(int i=1;i<m;i++){
        for(int j=0;j<n;j++){
            int up = matrix[i][j]+dp[i-1][j];
            int left=INT_MAX;
            if(j-1>=0) left=matrix[i][j]+dp[i-1][j-1];
            int right = INT_MAX;
            if(j+1<n) right = matrix[i][j]+dp[i-1][j+1];
            dp[i][j]=min(up,min(left,right));
        }

    }
    int final_sum=INT_MAX;
    for(int i=0;i<n;i++) final_sum=min(final_sum,dp[n-1][i]);
    return final_sum;
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        return solve(matrix,m,n);
    }
};