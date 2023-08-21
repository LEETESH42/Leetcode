class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans=0;

        int n=nums.size();
        stack<int> st;

        vector<int> mprev(n,-1), mnext(n,n), maprev(n,-1), manext(n,n);

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                mprev[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(!st.empty()){
                mnext[i]=st.top();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                maprev[i]=st.top();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            if(!st.empty()){
                manext[i]=st.top();
            }
            st.push(i);
        }

        for(int i=0;i<n;i++){
            long long lmin=i-mprev[i], rmin=mnext[i]-i;
            long long lmax=i-maprev[i], rmax=manext[i]-i;
            ans+=(lmax*rmax-lmin*rmin)*nums[i];
        }
        return ans;
    }
};