class Solution {
public:
    // int solve(int i,int amount, vector<int>& coins, vector<vector<int>>& dp){
    //     if(i==0){
    //         if(amount%coins[i]==0){
    //             return amount/coins[i];
    //         }
    //         else{
    //             return 1e9;
    //         }
    //     }
    //     if(dp[i][amount]!=-1){
    //         return dp[i][amount];
    //     }

    //     int nottake=solve(i-1,amount,coins,dp);
    //     int take=1e9;
    //     if(amount>=coins[i]){
    //         take=1+solve(i,amount-coins[i],coins,dp);
    //     }
    //     return dp[i][amount]=min(take,nottake);
    // }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+2,0));

        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i]=i/coins[0];
            }
            else{
                dp[0][i]=1e9;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int notpick=dp[i-1][j];
                int pick=1e9;

                if(j>=coins[i]){
                    pick=1+dp[i][j-coins[i]];
                }
                dp[i][j]=min(notpick,pick);
            }
        }

        int ans=dp[n-1][amount];
        if(ans>=1e9){
            return -1;
        }
        return dp[n-1][amount];
    }
};