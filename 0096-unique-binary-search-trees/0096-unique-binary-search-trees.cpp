class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=0;
        // taking a node at a time and then solving it for the left part and right part
        for(int i=1;i<=n;i++){
            ans+=solve(i-1,dp)*solve(n-i,dp);
        }
        return dp[n]=ans;
    }

    int numTrees(int n) {
        vector<int> dp(n+1,0);
        // return solve(n,dp);
        dp[0]=dp[1]=1;
        // i-> number of nodes
        for(int i=2;i<=n;i++){
            // j->number of root
            for(int j=1;j<=i;j++){
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};