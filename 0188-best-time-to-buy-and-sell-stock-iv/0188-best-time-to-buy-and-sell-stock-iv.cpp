class Solution {
public:
    int solve(int ind, int buy, int trnsc, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(trnsc==0){
            return 0;
        }
        if(ind==prices.size()){
            return 0;
        }

        if(dp[ind][buy][trnsc]!=-1){
            return dp[ind][buy][trnsc];
        }
        
        if(buy==1){
            return dp[ind][buy][trnsc]=max(-prices[ind]+solve(ind+1,0,trnsc,prices,dp), solve(ind+1,1,trnsc,prices,dp));
        }
        else{
            return dp[ind][buy][trnsc]=max(prices[ind]+solve(ind+1,1,trnsc-1,prices,dp), solve(ind+1,0,trnsc,prices,dp));
        }

    }

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));

        return solve(0,1,k,prices,dp);
    }
};