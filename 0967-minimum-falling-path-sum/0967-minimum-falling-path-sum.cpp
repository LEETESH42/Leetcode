class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>>& dp, vector<vector<int>>& matrix){
        if(j<0 || j>n-1){
            return 1e5;
        }
        if(i==0){
            return matrix[0][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ld=matrix[i][j]+solve(i-1,j-1,n,dp,matrix);
        int s=matrix[i][j]+solve(i-1,j,n,dp,matrix);
        int rd=matrix[i][j]+solve(i-1,j+1,n,dp,matrix);

        return dp[i][j]=min(ld,min(s,rd));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        int maxi=INT_MAX;
        for(int j=0;j<n;j++){
            maxi=min(maxi,solve(n-1,j,n,dp,matrix));
        }
        return maxi;
    }
};