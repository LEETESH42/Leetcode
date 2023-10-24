class Solution {
public:
    const int mod=1e9+7;

    int solve(int n, int& mp, vector<int>& grp, vector<int>& prft, int i, int curr, vector<vector<vector<int>>> &dp){
        if(i>=grp.size() && n>=0 && curr>=mp){
            return 1;
        }
        if(i>=grp.size() || n<0){
            return 0;
        }
        if(dp[n][i][min(curr,mp)]!=-1){
            return dp[n][i][min(curr,mp)]%mod;
        }

        int c1=0;
        int c2=0;

        c1=solve(n-grp[i],mp,grp,prft,i+1,curr+prft[i],dp);
        c2=solve(n,mp,grp,prft,i+1,curr,dp);
        return dp[n][i][min(curr,mp)]=(c1+c2)%mod;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(group.size(),vector<int>(minProfit+1,-1)));
        return solve(n,minProfit,group,profit,0,0,dp);
    }
};