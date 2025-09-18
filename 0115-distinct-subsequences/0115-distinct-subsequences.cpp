class Solution {
public:
int dp[1001][1001];
    int numDistinct(string s, string t) {
        int mod = 1e9+7;
        int m = s.size();
        int n = t.size();
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
            }
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(s[i-1]==t[j-1])
                dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[m][n];
    }
};