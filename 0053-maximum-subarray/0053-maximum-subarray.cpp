class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int cumsum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(cumsum<0){
                cumsum=0;
            }
            cumsum+=nums[i];
            ans=max(cumsum,ans);
        }
        return ans;
    }
};