class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            st.push(nums[i]);
        }
        vector<int> ans;
        for(int j=n-1;j>=0;j--){
            if(st.size()==0){
                ans.push_back(-1);
            }
            else if(st.size()>0 && st.top()>nums[j]){
                ans.push_back(st.top());
            }
            else if(st.size()>0 && st.top()<=nums[j]){
                while(st.size()>0 && st.top()<=nums[j]){
                    st.pop();
                }
                if(st.size()==0){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(st.top());
                }
            }
            st.push(nums[j]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};