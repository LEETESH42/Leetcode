class Solution {
public:
    int solve(int n, vector<int> & dp){
        if(n==0 || n==1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int mx=0;

        for(int i=1;i<n;i++){
            int temp=max(i*(n-i), i*solve(n-i,dp));
            mx=max(mx,temp);
        }
        return dp[n]=mx;
    }

    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};