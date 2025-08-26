class Solution {
public:
int sumbyd(vector<int>& nums,int div){
    int sum=0;
    for(int i=0;i<nums.size();i++)
    sum+=ceil((double)nums[i]/(double)div);
    return sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
      int low=1,high=*max_element(nums.begin(),nums.end());
      while(low<=high){
        int mid = (low+high)/2;
        if(sumbyd(nums,mid)<=threshold) high=mid-1;
        else low=mid+1;
      }  
       return low; 
    }
};