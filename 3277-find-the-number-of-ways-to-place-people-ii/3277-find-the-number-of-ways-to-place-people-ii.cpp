class Solution {
public:
    bool static comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]<b[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        int cnt=0;
        sort(points.begin(),points.end(),comp);
        for(int i=n-2;i>=0;i--){
            int ymax=INT_MIN;
            for(int j=i+1;j<n;j++){
                int x1=points[i][0];
                int x2=points[j][0];
                int y1=points[i][1];
                int y2=points[j][1];
                if(x1<=x2 && y1>=y2){
                    if(y2>ymax){
                        cnt++;
                    }
                    ymax=max(y2,ymax);
                }
            }
        }
        return cnt;
    }
};