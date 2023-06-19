class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int index, int n){
        if(index==n-1){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int ans=1e5;
        for(int i=index+1; i<=min(n-1,index+nums[index]); i++){
            ans=min(ans,solve(nums,dp,i,n)+1);
        }
        return dp[index]=ans;
    }

    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return solve(nums,dp,0,n);
    }
};