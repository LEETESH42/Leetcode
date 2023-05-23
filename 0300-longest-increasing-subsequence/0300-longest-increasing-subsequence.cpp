class Solution {
public:
    int solve(int ind, int prev, int n, vector<int>& nums, vector<vector<int>>& dp){
        if(ind==n){
            return 0;
        }
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        dp[ind][prev+1]=solve(ind+1,prev,n,nums,dp);
        if(prev==-1 || nums[ind]>nums[prev]){
            dp[ind][prev+1]=max(dp[ind][prev+1], 1+solve(ind+1,ind,n,nums,dp));
        }
        return dp[ind][prev+1];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,n,nums,dp);
    }
};