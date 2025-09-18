class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> ahead(2,0);
        vector<int> cur(2,0);
        ahead[0]=ahead[1]=0;
        int n = prices.size();
        int profit;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy==0) profit=max(0+ahead[0],-prices[i]+ahead[1]);
                if(buy==1) profit=max(0+ahead[1],prices[i]+ahead[0]);
                cur[buy]=profit;
            }
            ahead=cur;
        }
        return cur[0];
    }
};