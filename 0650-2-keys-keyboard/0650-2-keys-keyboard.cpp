class Solution {
public:
    int dp[1001][1001];

    int solve(int curr, int c, int n){
        if(curr==n){
            return 0;
        }

        if(dp[curr][c]!=-1){
            return dp[curr][c];
        }

        int copy=1e9, paste=1e9;

        if(curr!=c){
            copy=1+solve(curr,curr,n);
        }

        if(curr+c<=n){
            paste=1+solve(curr+c, c, n);
        }
        return dp[curr][c]=min(copy,paste);
    }

    int minSteps(int n) {
        memset(dp,-1,sizeof(dp));
        if(n==1){
            return 0;
        }
        if(n==2){
            return 2;
        }
        return 2+solve(2,1,n);
    }
};