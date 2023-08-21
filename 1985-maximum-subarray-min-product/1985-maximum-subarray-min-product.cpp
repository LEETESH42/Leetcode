class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();
        int mod=1e9+7;

        vector<long long> prefix(n);
        vector<int> mnIndices(n);

        stack<int> st;

        prefix[0]=nums[0];
        st.push(0);
        mnIndices[0]=-1;

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
            while(!st.empty() && nums[i]<=nums[st.top()]){
                st.pop();
            }
            mnIndices[i]=st.empty()?-1:st.top();
            st.push(i);
        }

        stack<int> st1;
        long long ans=0;

        for(int i=n-1;i>=0;i--){
            while(!st1.empty() && nums[i]<=nums[st1.top()]){
                st1.pop();
            }
            long long right=st1.empty()?prefix[n-1]:prefix[st1.top()-1];
            long long left=mnIndices[i]==-1?0:prefix[mnIndices[i]];

            ans=max(ans,(right-left)*nums[i]);
            st1.push(i);
        }
        return (int)(ans%mod);
    }
};