class Solution {
public:
    int solve(int i, vector<int>& nums, int r, vector<vector<int>>& dp){
        if(i==nums.size()){
            if(r==0){
                return 0;
            }
            return -1000000;
        }
        
        if(dp[i][r]!=-1){
            return dp[i][r];
        }

        int op1=nums[i]+solve(i+1,nums,(r+nums[i])%3, dp);
        int op2=solve(i+1,nums,r,dp);

        return dp[i][r]=max(op1,op2);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(3,-1));
        return solve(0,nums,0,dp);
    }
};