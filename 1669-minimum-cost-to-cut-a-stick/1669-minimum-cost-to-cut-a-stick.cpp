class Solution {
public:
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mn=INT_MAX;
        
        for(int k=i;k<=j;k++){
            int steps=cuts[j+1]-cuts[i-1]+solve(i,k-1,cuts,dp)+solve(k+1,j,cuts,dp);
            if(steps<mn){
                mn=steps;
            }
        }
        return dp[i][j]=mn;
    }

    int minCost(int n, vector<int>& cuts) {
        int sz=cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end()); 
        vector<vector<int>> dp(sz+1, vector<int>(sz+1,-1));

        return solve(1,sz,cuts,dp);
    }
};