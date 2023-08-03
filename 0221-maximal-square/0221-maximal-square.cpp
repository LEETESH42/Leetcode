class Solution {
public:
    int solve(vector<vector<char>>& mat, int i, int j, int& mx, vector<vector<int>>& dp){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int right=solve(mat,i,j+1,mx,dp);
        int dignl=solve(mat,i+1,j+1,mx,dp);
        int down=solve(mat,i+1,j,mx,dp);

        if(mat[i][j]=='1'){
            dp[i][j]=1+min(right,min(dignl,down));
            mx=max(mx,dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j]=0;
        }
    }

    int maximalSquare(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        int mx=0;
        solve(mat,0,0,mx,dp);
        return mx*mx;
    }
};