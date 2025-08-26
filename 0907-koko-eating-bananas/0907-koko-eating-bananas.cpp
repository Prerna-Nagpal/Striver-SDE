class Solution {
public:
    int find_max(vector<int>& piles){
        int n = piles.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(piles[i],maxi);
        }
        return maxi;
    }
    long long calc(vector<int>& piles,int hourly){
        int n = piles.size();
        long long totalh=0;
        for(int i=0;i<n;i++){
            totalh+=ceil((double)piles[i]/(double)hourly);
        }
        return totalh;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
       int low=1,high=find_max(piles);
       while(low<=high){
        int mid = (low+high)/2;
        long long total = calc(piles,mid);
        if(total<=h) high=mid-1;
        else low=mid+1;
       }
       return low;
    }
};