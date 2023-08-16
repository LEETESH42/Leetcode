class Solution {
public:

    vector<int> nsl(vector<int>& nums, int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);

        for(int i=0;i<n;i++){
            int curr=nums[i];
            while((st.top()!=-1) && (nums[st.top()]>=curr)){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> nsr(vector<int>& nums, int n){
        stack<int> st;
        st.push(-1);

        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){
            int curr=nums[i];
            while((st.top()!=-1) && (nums[st.top()]>=curr)){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        vector<int> next(n);
        next=nsr(heights,n);

        vector<int> pre(n);
        pre=nsl(heights,n);

        int ans=INT_MIN;

        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }

            int bre=next[i]-pre[i]-1;
            int area=l*bre;
            ans=max(ans,area);
        }
        return ans;
    }
};