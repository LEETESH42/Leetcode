class Solution {
public:

    int solve(int n,vector<int> &dp){
        if(n==0 || n==1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n-1]=solve(n-1,dp);
        dp[n-2]=solve(n-2,dp);
        return dp[n]=dp[n-1]+dp[n-2];
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};