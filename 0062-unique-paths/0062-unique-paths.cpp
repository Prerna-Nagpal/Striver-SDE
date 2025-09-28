class Solution {
public:
    int uniquePaths(int m, int n) {
        int total = m+n-2;
        int right = m-1;
        double ans = 1;
        for(int i=1;i<=right;i++){
            ans = ans*(total-right+i)/i;
        }
        return (int)ans;
    }
};