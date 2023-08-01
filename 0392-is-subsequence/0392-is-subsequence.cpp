class Solution {
public:
    
    bool solve(int i, string s, int j, string t, vector<vector<int>>& dp){
        
        if(i<0 && j>=0){
            return true;
        }
        if(i<0 && j<0){
            return true;
        }
        if(i>=0 && j<0){
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==t[j]){
            dp[i][j]=solve(i-1,s,j-1,t,dp);
        }
        else{
            dp[i][j]=solve(i,s,j-1,t,dp);
        }
        return dp[i][j];
    }

    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(s.size()-1,s,t.size()-1,t,dp);
    }
};