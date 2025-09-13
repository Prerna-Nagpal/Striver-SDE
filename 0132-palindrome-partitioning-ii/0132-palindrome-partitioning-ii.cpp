class Solution {
public:
    int t[2001][2001];
    bool ispalin(string& s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
   int solve(string& s,int i,int j){
    if(i>=j) return 0;
    if(t[i][j]!=-1) return t[i][j];
    if(ispalin(s,i,j)) return 0;
    int res= INT_MAX;
    for(int k=i;k<j;k++){
        int left,right;
        if(ispalin(s,i,k)){
        if(t[i][k]!=-1) left=t[i][k];
        else{
            left=solve(s,i,k);
            t[i][k]=left;
        }
        if(t[k+1][j]!=-1) right=t[k+1][j];
        else{
            right=solve(s,k+1,j);
            t[k+1][j]=right;
        }
        int temp = 1+left+right;
        res=min(temp,res);}
    }
    return t[i][j]=res;
   }
    int minCut(string s) {
        int n = s.length();
        int i=0,j=n-1;
        memset(t,-1,sizeof(t));
        return solve(s,i,j);
        
    }
};