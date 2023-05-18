class Solution {
public:
    // int count(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp){
    //     if(ind==0){
    //         return (amount%coins[0]==0);
    //     }
    //     if(dp[ind][amount]!=-1){
    //         return dp[ind][amount];
    //     }

    //     int notTake=count(ind-1,amount,coins,dp);
    //     int take=0;
    //     if(amount>=coins[ind]){
    //         take=count(ind,amount-coins[ind],coins,dp);
    //     }

    //     return dp[ind][amount]=(notTake+take);
    // }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i]=1;
            }
        }

        for(int i=1;i<n;i++){   
            for(int tar=0;tar<=amount;tar++){
                int notTake=dp[i-1][tar];
                int take=0;
                if(coins[i]<=tar){
                    take=dp[i][tar-coins[i]];
                }
                dp[i][tar]=notTake+take;
            }
        }
        return dp[n-1][amount];
    }
};