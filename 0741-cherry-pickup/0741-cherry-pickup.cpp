class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j1,int j2, int n, vector<vector<vector<int>>> &dp){
        int i2=i+j1-j2;

        if(i==n || i2==n || j1==n || j2==n || grid[i][j1]==-1 || grid[i2][j2]==-1){
            return -1e9;
        }
        if(i==n-1 && j1==n-1){
            return grid[i][j1];
        }
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        int ans=grid[i][j1];
        if(j1!=j2){
            ans+=grid[i2][j2];
        }

        ans+=max(max(solve(grid,i,j1+1,j2+1,n,dp), solve(grid,i+1,j1,j2+1,n,dp)), max(solve(grid,i,j1+1,j2,n,dp), solve(grid,i+1,j1,j2,n,dp)));
        return dp[i][j1][j2]=ans;

    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return max(0,solve(grid,0,0,0,n,dp));
    }
};