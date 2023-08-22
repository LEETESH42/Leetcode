class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int val=arr[i];
            while(!st.empty() && arr[i]<st.top()){
                val=max(val,st.top());
                st.pop();
            }
            st.push(val);
        }
        return st.size();
    }
};