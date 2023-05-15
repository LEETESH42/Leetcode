class Solution {
public:
    int solve(int i, int j1, int j2, int n, int m, vector<vector<vector<int>>>& dp, vector<vector<int>>& grid){

        if(j1<0 || j1>=m || j2<0 || j2>=m){
            return -1e5;
        }

        if(i==n-1){
            if(j1==j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1]+grid[i][j2];
            }
        }

        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }

        int maxi=INT_MIN;

        for(int d1=-1;d1<2;d1++){
            for(int d2=-1;d2<2;d2++){
                int value=0;
                if(j1==j2){
                    value+=grid[i][j1];
                }
                else{
                    value+=grid[i][j1]+grid[i][j2];
                }
                value+=solve(i+1,j1+d1,j2+d2,n,m,dp,grid);
                maxi=max(value,maxi);

            }
        }
        return dp[i][j1][j2]=maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return solve(0,0,m-1,n,m,dp,grid);

    }
};