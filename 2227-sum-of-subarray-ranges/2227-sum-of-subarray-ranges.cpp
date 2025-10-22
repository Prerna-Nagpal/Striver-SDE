class Solution {
public:
vector<int> pge(vector<int>& nums){
    int n = nums.size();
    vector<int> pge(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
        pge[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return pge;
}
vector<int> pse(vector<int>& nums){
    int n = nums.size();
    vector<int> pse(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
        pse[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return pse;
}
vector<int> nge(vector<int>& nums){
    int n = nums.size();
    vector<int> nge(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
        nge[i]=st.empty()?n:st.top();
        st.push(i);
    }
    return nge;
}
vector<int> nse(vector<int>& nums){
    int n = nums.size();
    vector<int> nse(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
        nse[i]=st.empty()?n:st.top();
        st.push(i);
    }
    return nse;
}
long long miniarraysum(vector<int>& nums){
    int n = nums.size();
    vector<int> nse1 = nse(nums);
    vector<int> psee = pse(nums);
    long long total=0;
    for(int i=0;i<n;i++){
        int left = i-psee[i];
        int right = nse1[i]-i;
        total+=(left*right*1LL*nums[i]);
    }
    return total;
}
long long maxiarraysum(vector<int>& nums){
    int n = nums.size();
    vector<int> ngee = nge(nums);
    vector<int> pge1 = pge(nums);
    long long total=0;
    for(int i=0;i<n;i++){
        int left = i-pge1[i];
        int right = ngee[i]-i;
        total+=(left*right*1LL*nums[i]);
    }
    return total;
}
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long maxsum = maxiarraysum(nums);
        long long minisum = miniarraysum(nums);
        return maxsum-minisum;
    }
};