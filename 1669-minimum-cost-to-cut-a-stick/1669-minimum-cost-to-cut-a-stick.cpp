class Solution {
public:
    //Aditya verma Approach 
    int solve (vector<int> & cuts, int i, int j, int start, int end, vector<vector<int>> & dp){
        
        if(start>end) return 0;     // --> Base condition is when no cutpoints left
        
        if(dp[start][end]!=-1) return dp[start][end];
        
        int ans = INT_MAX;
        
        for(int k=start; k<=end; k++){
            
            int temp = solve(cuts, i, cuts[k], start, k-1, dp) + solve(cuts, cuts[k], j, k+1, end, dp) + j-i;
            ans = min(ans, temp);
        }
        
        return dp[start][end] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        int len = cuts.size();
        
        /* We sort the cuts vector so we can easily itearte for cut points for any part of the stick */
        
        sort(cuts.begin(), cuts.end());   
        
        vector<vector<int>> dp (len, vector<int> (len, -1));
        return solve (cuts, 0, n, 0, len-1, dp);
        
    }
};