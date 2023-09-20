class Solution {
public:
    int solve(int n, vector<int>&dp){
        if(n<=0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        for(int i=1;i*i<=n;i++){
            if(solve(n-i*i,dp)==0){
                return dp[n]=1;
            }
        }
        return dp[n]=0;
    }
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};