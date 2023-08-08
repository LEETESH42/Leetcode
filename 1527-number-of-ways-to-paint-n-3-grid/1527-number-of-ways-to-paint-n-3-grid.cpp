class Solution {
public:
    int MOD=1e9+7;
    int dp[5001][4][4][4];

    int help(int n, int x, int y, int z){
        if(n<0){
            return 1;
        }
        int ans=0;

        if(dp[n][x][y][z]!=-1){
            return dp[n][x][y][z];
        }

        for(int i=1;i<4;i++){
            for(int j=1;j<4;j++){
                for(int k=1;k<4;k++){
                    if(i==x || j==y || k==z || i==j || j==k){
                        continue;
                    }
                    ans+=help(n-1,i,j,k);
                    ans%=MOD;
                }
            }
        }
        return dp[n][x][y][z]=ans;
    }

    int numOfWays(int n) {
        memset(dp,-1,sizeof(dp));
        return help(n-1,0,0,0);
    }
};