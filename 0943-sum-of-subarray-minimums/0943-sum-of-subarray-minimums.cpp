class Solution {
public:
//TC -> O(5N),SC same
vector<int> findnse(vector<int>& arr){
    int n = arr.size();
    vector<int> nsee(n);
    stack<int> st1;
    for(int i=n-1;i>=0;i--){
        while(!st1.empty() && arr[st1.top()]>=arr[i]) st1.pop();
        nsee[i] = st1.empty()?n:st1.top();
        st1.push(i);
    }
    return nsee;
}
vector<int> findpse(vector<int>& arr){
    int n = arr.size();
    vector<int>psee(n);
    stack<int> st2;
    for(int i=0;i<n;i++){
        while(!st2.empty() && arr[st2.top()]>arr[i]) st2.pop();
        psee[i] = st2.empty()?-1:st2.top();
        st2.push(i);

    }
    return psee;
}
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findnse(arr);
        vector<int> pse = findpse(arr);
        int total=0;
        int mod = (int)(1e9+7);
        for(int i=0;i<arr.size();i++){
            int left = i-pse[i];
            int right = nse[i]-i;
            total = (total+(left*right*1LL*arr[i])%mod)%mod;
        }
        return total;
    }
};