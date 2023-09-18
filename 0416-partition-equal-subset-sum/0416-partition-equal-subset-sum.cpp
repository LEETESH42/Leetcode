class Solution {
public:
    int solve(int i, vector<int>& nums, int target, vector<vector<int>>& dp){
        if(target==0){
            return 1;
        }
        if(i>=nums.size()){
            return 0;
        }
        if(target<0){
            return 0;
        }

        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        return dp[i][target]=solve(i+1,nums,target-nums[i],dp)||solve(i+1,nums,target,dp);

    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum&1){
            return 0;
        }

        vector<vector<int>> dp(n,vector<int>(sum+1,-1));

        return solve(0,nums,sum/2,dp);
    }
};