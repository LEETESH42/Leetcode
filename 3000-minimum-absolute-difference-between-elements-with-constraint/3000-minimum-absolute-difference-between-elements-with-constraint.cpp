class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n=nums.size();

        set<int> st;
        int ans=INT_MAX;

        for(int i=0,j=x;j<n;i++,j++){
            st.insert(nums[i]);

            auto temp=st.lower_bound(nums[j]);
            if(temp==st.end()){
                temp--;
                ans=min(ans,nums[j]-*temp);
            }
            else if(temp==st.begin()){
                ans=min(ans,*temp-nums[j]);
            }
            else{
                ans=min(ans,*temp-nums[j]);
                temp--;
                ans=min(ans,nums[j]-*temp);
            }
        }
        return ans;
    }
};