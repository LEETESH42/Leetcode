class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n,0);

        int sum=0;
        int mod=1e9+7;

        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            int sum1=0;

            if(st.empty()){
                sum1=(sum1+(i+1)*arr[i])%mod;
            }
            else{
                sum1=(sum1+(i-st.top())*arr[i] +ans[st.top()])%mod;
            }
            ans[i]=sum1;
            sum=(sum+sum1)%mod;
            st.push(i);
        }
        return sum;
    }
};