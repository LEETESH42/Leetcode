class Solution {
public:
    long long dp[1001][1001];
    long long solve(int st, int end, string& text){
        if(st>end){
            return 0;
        }

        if(st==end){
            return 1;
        }
        if(dp[st][end]!=-1){
            return dp[st][end];
        }

        long long mx=1;
        int n=end-st+1;

        for(int i=1;i<=n/2;i++){
            string left=text.substr(st,i);
            string right=text.substr(end-i+1,i);
            if(left==right){
                mx=max(mx,2+solve(st+i,end-i,text));
            }
        }
        return dp[st][end]=mx;
    }
    int longestDecomposition(string text) {
        memset(dp,-1,sizeof(dp));
        int n=text.size();
        return solve(0,n-1,text);
    }
};