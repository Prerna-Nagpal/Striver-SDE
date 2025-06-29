class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
         int n = heights.size();
         stack<int> st;
         int maxarea=0;
         for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int ele = st.top();
                st.pop();
                int nse = i,pse = st.empty()?-1:st.top();
                maxarea = max(maxarea,heights[ele]*(nse-pse-1));
            }
            st.push(i);
         }
         while(!st.empty()){
            int nse =n;
            int ele = st.top();st.pop();
            int pse = st.empty()?-1:st.top();
            maxarea = max(maxarea,heights[ele]*(nse-pse-1));

         }
         return maxarea;
        
    }
};