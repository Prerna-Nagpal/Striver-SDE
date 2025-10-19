class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0,j=n-1;
        int mx=0;
        while(i<j){
            int water = (j-i)*min(height[i],height[j]);
            mx=max(water,mx);
            if(height[i]<height[j]) i++;
            else j--;
        }
        return mx;
    }
};