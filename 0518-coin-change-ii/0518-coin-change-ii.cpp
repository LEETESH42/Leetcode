class Solution {
public:
    int count(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(ind==0){
            return (amount%coins[0]==0);
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }

        int notTake=count(ind-1,amount,coins,dp);
        int take=0;
        if(amount>=coins[ind]){
            take=count(ind,amount-coins[ind],coins,dp);
        }

        return dp[ind][amount]=(notTake+take);
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1,-1));
        return count(n-1,amount,coins,dp);
    }
};