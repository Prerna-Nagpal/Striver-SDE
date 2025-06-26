class Solution {
public:
 //TC-O(2N)--2N isliye kyunki har baari N ke liye ni chalega,intotal N ke liye chalega
 //SC-O(N)+O(N)
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    map<int,int>mp;
    int n = nums2.size();
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<=nums2[i]) st.pop();
        if(st.empty()) mp[nums2[i]]=-1;
        else mp[nums2[i]] = st.top();
        st.push(nums2[i]);
    }
    vector<int> ans(nums1.size());
    for(int i=0;i<nums1.size();i++){
        ans[i]=mp[nums1[i]];
    }
    return ans;
    }
};