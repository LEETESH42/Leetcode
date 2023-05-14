class Solution {
public:
    // int count(int m, int n, vector<vector<int>> &dp){

    //     if(m==0 || n==0){
    //         return 1;
    //     }
    //     if(m<0 || n<0){
    //         return 0;
    //     }
    //     if(dp[m][n]!=-1){
    //         return dp[m][n];
    //     }

    //     int left=count(m,n-1,dp);
    //     int up=count(m-1,n,dp);

    //     return dp[m][n]=left+up;
    // }

    int uniquePaths(int m, int n) {
        //vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        // for(int i=0;i<n;i++){
        //     dp[0][i]=1;
        // }
        // for(int i=1;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         dp[i][j]=dp[i-1][j];
        //         if(j>0){
        //             dp[i][j]+=dp[i][j-1];
        //         }
        //     }
        // }
        // return dp[m-1][n-1];

        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> cur(n,0);
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    cur[j]=1;
                }
                else{
                    int up=0,left=0;
                    if(i>0){
                        up=prev[j];
                    }
                    if(j>0){
                        left=cur[j-1];
                    }
                    cur[j]=up+left;
                }

            }
            prev=cur;
        }
        return prev[n-1];
    }
};